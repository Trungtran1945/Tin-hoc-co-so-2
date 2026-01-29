// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int a[100][100];
//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         a[x][y] = a[y][x] = 1;
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             cout << a[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
// .
// .
// .

#include <iostream>
#include <string>
#include <unordered_map>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>

using namespace std;

// ==== Prototype & tiện ích ====
struct thongTin;
bool kiemTraSoDienThoaiHopLe(const string &sdt);
void hienThiMenu();
int demKyTuUTF8(const string &str);
string canLeTraiUTF8(const string &str, int width);

// ==== Định nghĩa struct ====
struct thongTin
{
    string ten;
    string sdt;
    thongTin() {}
    thongTin(string t, string s) : ten(t), sdt(s) {}
};

// ==== Lớp quản lý danh bạ ====
class DSLienHe
{
public:
    unordered_map<string, thongTin> theoTen;   // tên → thongTin
    unordered_map<string, thongTin *> theoSDT; // sdt → pointer thongTin

    // --- Kiểm tra ---
    bool tonTaiTen(const string &ten) { return theoTen.count(ten) > 0; }
    bool tonTaiSDT(const string &sdt) { return theoSDT.count(sdt) > 0; }
    bool kiemTraTen(const string &ten);

    // --- Thêm/xóa/sửa ---
    bool themSDT(const string &ten, const string &sdt);
    void xoaLienHe();
    void suaLienHe();

    // --- Tìm kiếm ---
    vector<thongTin *> timKiem(const string &tuKhoa);
    void timKiemLienHe();

    // --- Hiển thị ---
    void hienThi();

    // --- Lưu/tải file ---
    void luuFile(const string &filename = "danhba.txt");
    void taiFile(const string &filename = "danhba.txt");

    // --- Chọn và xử lý liên hệ ---
    void chonVaXuLyLienHe(vector<thongTin *> &ds);
};

// ==== Triển khai các hàm tiện ích ====
bool kiemTraSoDienThoaiHopLe(const string &sdt)
{
    if (sdt.empty())
        return false;
    for (char c : sdt)
        if (!isdigit(c))
            return false;
    return true;
}

void hienThiMenu()
{
    system("cls");
    cout << "\n";
    cout << "╔══════════════════════════════════════╗\n";
    cout << "║     📱 QUẢN LÝ DANH BẠ - MENU        ║\n";
    cout << "╠══════════════════════════════════════╣\n";
    cout << "║ 1. Thêm liên hệ                      ║\n";
    cout << "║ 2. Xoá liên hệ theo tên/SĐT          ║\n";
    cout << "║ 3. Sửa liên hệ                       ║\n";
    cout << "║ 4. Hiển thị tất cả danh bạ           ║\n";
    cout << "║ 5. Tìm kiếm liên hệ                  ║\n";
    cout << "║ 0. Thoát                             ║\n";
    cout << "╚══════════════════════════════════════╝\n";
    cout << "👉 Mời bạn chọn chức năng: ";
}

int demKyTuUTF8(const string &str)
{
    int count = 0;
    for (size_t i = 0; i < str.size();)
    {
        unsigned char c = str[i];
        if ((c & 0x80) == 0)
            i += 1;
        else if ((c & 0xE0) == 0xC0)
            i += 2;
        else if ((c & 0xF0) == 0xE0)
            i += 3;
        else if ((c & 0xF8) == 0xF0)
            i += 4;
        else
            i += 1;
        ++count;
    }
    return count;
}

string canLeTraiUTF8(const string &str, int width)
{
    int len = demKyTuUTF8(str);
    string res = str;
    if (len < width)
        res += string(width - len, ' ');
    return res;
}

// ==== Triển khai các phương thức của DSLienHe ====

// --- Kiểm tra tên hợp lệ ---
bool DSLienHe::kiemTraTen(const string &ten)
{
    if (ten.empty())
    {
        cout << "❌ Tên không được để trống.\n";
        return false;
    }
    if (tonTaiTen(ten))
    {
        cout << "❌ Tên liên hệ đã tồn tại.\n";
        return false;
    }
    return true;
}

// --- Thêm liên hệ ---
bool DSLienHe::themSDT(const string &ten, const string &sdt)
{
    if (tonTaiTen(ten) || tonTaiSDT(sdt))
        return false;
    theoTen[ten] = thongTin(ten, sdt);
    theoSDT[sdt] = &theoTen[ten];
    cout << "✅ Đã thêm liên hệ: " << ten << " - " << sdt << "\n";
    return true;
}

// --- Xóa liên hệ ---
void DSLienHe::xoaLienHe()
{
    if (theoTen.empty())
    {
        cout << "📭 Danh bạ trống. Không có liên hệ để xóa.\n";
        return;
    }
    string nhap;
    cout << "🔍 Nhập tên hoặc số điện thoại cần xóa: ";
    getline(cin, nhap);
    string ten;
    if (kiemTraSoDienThoaiHopLe(nhap))
    {
        if (!tonTaiSDT(nhap))
        {
            cout << "❌ Không tìm thấy liên hệ với số điện thoại này.\n";
            return;
        }
        ten = theoSDT[nhap]->ten;
    }
    else
    {
        if (!tonTaiTen(nhap))
        {
            cout << "❌ Không tìm thấy liên hệ với tên này.\n";
            return;
        }
        ten = nhap;
    }
    string sdt = theoTen[ten].sdt;

    cout << "Bạn có chắc muốn xóa liên hệ: " << ten << " - " << sdt << "? (y/n): ";
    char xacNhan;
    cin >> xacNhan;
    cin.ignore();

    theoTen.erase(ten);
    theoSDT.erase(sdt);
    cout << "✅ Đã xóa liên hệ.\n";
}

// --- Sửa liên hệ ---
void DSLienHe::suaLienHe()
{
    if (theoTen.empty())
    {
        cout << "📭 Danh bạ trống. Không có liên hệ để sửa.\n";
        _getch();
        return;
    }
    string input;
    cout << "🔍 Nhập tên hoặc số điện thoại liên hệ cần sửa: ";
    getline(cin, input);
    string ten;
    if (kiemTraSoDienThoaiHopLe(input))
    {
        if (!tonTaiSDT(input))
        {
            cout << "❌ Không tìm thấy liên hệ với số điện thoại này.\n";
            _getch();
            return;
        }
        ten = theoSDT[input]->ten;
    }
    else
    {
        if (!tonTaiTen(input))
        {
            cout << "❌ Không tìm thấy liên hệ với tên này.\n";
            _getch();
            return;
        }
        ten = input;
    }
    thongTin &lh = theoTen[ten];
    cout << "📋 Thông tin hiện tại:\n";
    cout << "\tTên: " << lh.ten << "\n";
    cout << "\tSĐT: " << lh.sdt << "\n";
    cout << "\n🔧 Bạn muốn sửa gì?\n";
    cout << "1. Sửa tên\n";
    cout << "2. Sửa số điện thoại\n";
    cout << "👉 Chọn: ";
    char chon;
    cin >> chon;
    cin.ignore();
    if (chon == '1')
    {
        string tenMoi;
        cout << "✏️ Nhập tên mới: ";
        getline(cin, tenMoi);
        if (tenMoi == ten)
        {
            cout << "⚠️ Tên mới giống tên cũ. Không có thay đổi.\n";
            _getch();
            return;
        }
        if (tonTaiTen(tenMoi))
        {
            cout << "❌ Tên liên hệ đã tồn tại.\n";
            _getch();
            return;
        }
        thongTin tmp = lh;
        tmp.ten = tenMoi;
        theoTen.erase(ten);
        theoTen[tenMoi] = tmp;
        theoSDT[tmp.sdt] = &theoTen[tenMoi];
        cout << "✅ Đã cập nhật tên.\n";
    }
    else if (chon == '2')
    {
        string sdtMoi;
        cout << "✏️ Nhập số điện thoại mới: ";
        getline(cin, sdtMoi);
        if (!kiemTraSoDienThoaiHopLe(sdtMoi))
        {
            cout << "❌ Số điện thoại không hợp lệ.\n";
            return;
        }
        if (sdtMoi == lh.sdt)
        {
            cout << "Số điện thoại mới giống số cũ.\n";
            return;
        }
        if (tonTaiSDT(sdtMoi))
        {
            cout << "❌ Số điện thoại đã tồn tại.\n";
            return;
        }
        theoSDT.erase(lh.sdt);
        lh.sdt = sdtMoi;
        theoSDT[sdtMoi] = &lh;
        cout << "✅ Đã cập nhật số điện thoại.\n";
    }
    else
    {
        cout << "❌ Lựa chọn không hợp lệ.\n";
    }
    _getch();
}

// --- Tìm kiếm fuzzy ---
vector<thongTin *> DSLienHe::timKiem(const string &tuKhoa)
{
    vector<thongTin *> ketQua;
    string tuKhoaLower = tuKhoa;
    transform(tuKhoaLower.begin(), tuKhoaLower.end(), tuKhoaLower.begin(), ::tolower);
    for (auto &p : theoTen)
    {
        string tenLower = p.second.ten, sdtLower = p.second.sdt;
        transform(tenLower.begin(), tenLower.end(), tenLower.begin(), ::tolower);
        transform(sdtLower.begin(), sdtLower.end(), sdtLower.begin(), ::tolower);
        if (tenLower.find(tuKhoaLower) != string::npos || sdtLower.find(tuKhoaLower) != string::npos)
            ketQua.push_back(&p.second);
    }
    return ketQua;
}

// --- Hàm dùng chung cho giao diện chọn/xử lý liên hệ ---
void DSLienHe::chonVaXuLyLienHe(vector<thongTin *> &ds)
{
    if (ds.empty())
    {
        cout << "❌ Không có liên hệ nào.\n";
        return;
    }
    int stt = 0;
    bool chon = false;
    while (!chon)
    {
        system("cls");
        cout << "\n📒 DANH SÁCH LIÊN HỆ (dùng ↑ ↓ để chọn, Enter để thao tác):\n";
        cout << "╔═══╦══════════════════════════════════════╦═══════════════════════════════════════════╗\n";
        cout << "║STT║                TÊN                   ║              SỐ ĐIỆN THOẠI                ║\n";
        cout << "╠═══╬══════════════════════════════════════╬═══════════════════════════════════════════╣\n";
        for (int i = 0; i < ds.size(); ++i)
        {
            if (i == stt)
                cout << "\033[7m";
            cout << "║" << left << setw(3) << (i + 1)
                 << "║" << canLeTraiUTF8(ds[i]->ten, 38)
                 << "║" << canLeTraiUTF8(ds[i]->sdt, 43) << "║\n";
            if (i == stt)
                cout << "\033[0m";
        }
        cout << "╚═══╩══════════════════════════════════════╩═══════════════════════════════════════════╝\n";
        cout << "↑/↓: di chuyển, Enter: chọn, Esc: thoát\n";
        int key = _getch();
        if (key == 224)
        {
            key = _getch();
            if (key == 72 && stt > 0)
                stt--;
            else if (key == 80 && stt < (int)ds.size() - 1)
                stt++;
        }
        else if (key == 13)
        {
            chon = true;
        }
        else if (key == 27)
        {
            return;
        }
    }
    // Sau khi chọn, hỏi thao tác
    system("cls");
    cout << "Bạn đã chọn:\n";
    cout << "Tên: " << ds[stt]->ten << "\n";
    cout << "SĐT: " << ds[stt]->sdt << "\n";
    cout << "1. Xóa liên hệ\n2. Sửa liên hệ\n0. Thoát\nChọn: ";
    char chon2;
    cin >> chon2;
    cin.ignore();
    string tenChon = ds[stt]->ten;
    if (chon2 == '1')
    {
        string sdt = ds[stt]->sdt;
        theoTen.erase(tenChon);
        theoSDT.erase(sdt);
        cout << "✅ Đã xóa liên hệ.\n";
        _getch(); // Thêm dòng này
    }
    else if (chon2 == '2')
    {
        thongTin &lh = theoTen[tenChon];
        cout << "1. Sửa tên\n2. Sửa số điện thoại\nChọn: ";
        char sua;
        cin >> sua;
        cin.ignore();
        if (sua == '1')
        {
            string tenMoi;
            cout << "Nhập tên mới: ";
            getline(cin, tenMoi);
            if (tenMoi == tenChon)
            {
                cout << "Tên mới giống tên cũ.\n";
                return;
            }
            if (tonTaiTen(tenMoi))
            {
                cout << "❌ Tên liên hệ đã tồn tại.\n";
                return;
            }
            thongTin tmp = lh;
            tmp.ten = tenMoi;
            theoTen.erase(tenChon);
            theoTen[tenMoi] = tmp;
            theoSDT[tmp.sdt] = &theoTen[tenMoi];
            cout << "✅ Đã cập nhật tên.\n";
        }
        else if (sua == '2')
        {
            string sdtMoi;
            cout << "Nhập số điện thoại mới: ";
            getline(cin, sdtMoi);
            if (!kiemTraSoDienThoaiHopLe(sdtMoi))
            {
                cout << "❌ Số điện thoại không hợp lệ.\n";
                return;
            }
            if (sdtMoi == lh.sdt)
            {
                cout << "Số điện thoại mới giống số cũ.\n";
                return;
            }
            if (tonTaiSDT(sdtMoi))
            {
                cout << "❌ Số điện thoại đã tồn tại.\n";
                return;
            }
            theoSDT.erase(lh.sdt);
            lh.sdt = sdtMoi;
            theoSDT[sdtMoi] = &lh;
            cout << "✅ Đã cập nhật số điện thoại.\n";
        }
        else
        {
            cout << "Lựa chọn không hợp lệ.\n";
        }
        _getch(); // Thêm dòng này sau khi sửa thành công
    }
}

// --- Tìm kiếm liên hệ ---
void DSLienHe::timKiemLienHe()
{
    if (theoTen.empty())
    {
        cout << "📭 Danh bạ trống. Không có liên hệ để tìm.\n";
        return;
    }
    string tuKhoa;
    cout << "🔍 Nhập tên hoặc số điện thoại (hoặc một phần): ";
    getline(cin, tuKhoa);
    vector<thongTin *> ketQua = timKiem(tuKhoa);
    if (ketQua.empty())
    {
        cout << "❌ Không tìm thấy liên hệ phù hợp.\n";
        return;
    }
    chonVaXuLyLienHe(ketQua);
}

// --- Hiển thị danh bạ ---
void DSLienHe::hienThi()
{
    if (theoTen.empty())
    {
        cout << "📭 Danh bạ trống.\n";
        return;
    }
    vector<thongTin *> ds;
    for (auto &p : theoTen)
        ds.push_back(&p.second);
    chonVaXuLyLienHe(ds);
}

// --- Lưu file ---
void DSLienHe::luuFile(const string &filename)
{
    ofstream fout(filename, ios::out | ios::trunc);
    fout << theoTen.size() << "\n";
    for (const auto &p : theoTen)
    {
        fout << p.second.ten << "\n"
             << p.second.sdt << "\n";
    }
    fout.close();
}

// --- Tải file ---
void DSLienHe::taiFile(const string &filename)
{
    ifstream fin(filename);
    if (!fin)
        return;
    theoTen.clear();
    theoSDT.clear();
    int n;
    fin >> n;
    fin.ignore();
    for (int i = 0; i < n; ++i)
    {
        string ten, sdt;
        getline(fin, ten);
        getline(fin, sdt);
        theoTen[ten] = thongTin(ten, sdt);
        theoSDT[sdt] = &theoTen[ten];
    }
    fin.close();
}

// ==== Hàm tiện ích nhập tên và số điện thoại ====

// Hàm nhập tên hợp lệ
string nhapTen(DSLienHe &ds)
{
    string ten;
    do
    {
        cout << "🔸 Tên: ";
        getline(cin, ten);
    } while (!ds.kiemTraTen(ten));
    return ten;
}

// Hàm nhập số điện thoại hợp lệ và không trùng
string nhapSDT(DSLienHe &ds)
{
    string sdt;
    char c = 'y';
    do
    {
        cout << "🔸 Số điện thoại: ";
        getline(cin, sdt);
        if (!kiemTraSoDienThoaiHopLe(sdt))
        {
            cout << "❌ Số điện thoại không hợp lệ. Vui lòng chỉ nhập số.\n";
            continue;
        }
        if (ds.tonTaiSDT(sdt))
        {
            cout << "❌ Số điện thoại đã tồn tại. Bạn có muốn nhập lại số điện thoại? (y/n): ";
            cin >> c;
            cin.ignore();
            if (c != 'y')
                return "";
        }
        else
            break;
    } while (true);
    return sdt;
}

// ==== Hàm main ====
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    DSLienHe ds;
    ds.taiFile();

    string tmpInput;
    int choice;

    do
    {
        hienThiMenu();
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1: // Thêm liên hệ
        {
            cout << "\n📨 Nhập thông tin liên hệ:\n";
            string ten = nhapTen(ds);
            string sdt = nhapSDT(ds);
            if (!sdt.empty())
                ds.themSDT(ten, sdt);
            _getch();
            break;
        }
        case 2: // Xóa liên hệ
            ds.xoaLienHe();
            _getch();
            break;
        case 3: // Sửa liên hệ
            if (ds.theoTen.empty())
            {
                cout << "📭 Danh bạ trống. Không có liên hệ để sửa.\n";
                _getch();
                break;
            }
            ds.suaLienHe();
            break;
        case 4: // Hiển thị danh bạ
            ds.hienThi();
            _getch();
            break;
        case 5: // Tìm kiếm liên hệ
            ds.timKiemLienHe();
            _getch();
            break;
        case 0: // Thoát
            ds.luuFile();
            cout << "Cảm ơn đã sử dụng 🫶\n";
            cout << "Hẹn gặp lại bạn sau! 👋\n";
            break;
        default:
            cout << "❌ Lựa chọn không hợp lệ.\n";
            _getch();
            break;
        }
    } while (choice);
    return 0;
}