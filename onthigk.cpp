#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class HocVien
{
private:
    string hoTen;
    double diem1, diem2, diem3;

public:
    HocVien(string hoTen, double diem1, double diem2, double diem3)
        : hoTen(hoTen), diem1(diem1), diem2(diem2), diem3(diem3) {}

    double tinhTongDiem() const
    {
        return diem1 + diem2 + diem3;
    }

    bool isDat() const
    {
        return tinhTongDiem() >= 15 && diem1 >= 4 && diem2 >= 4 && diem3 >= 4;
    }

    string getHoTen() const
    {
        return hoTen;
    }

    void xuatThongTin() const
    {
        cout << "HocVien: " << hoTen
             << ", Diem1: " << diem1 << ", Diem2: " << diem2
             << ", Diem3: " << diem3 << ", TongDiem: " << tinhTongDiem() << endl;
    }
};

class NhanVien
{
private:
    string hoTen;
    string phongBan;
    int luong;
    string namSinh;
    string ngayNhanViec;

public:
    NhanVien(string hoTen, string phongBan, int luong, string namSinh, string ngayNhanViec)
        : hoTen(hoTen), phongBan(phongBan), luong(luong), namSinh(namSinh), ngayNhanViec(ngayNhanViec) {}

    string getPhongBan() const
    {
        return phongBan;
    }

    int getLuong() const
    {
        return luong;
    }

    string getNamSinh() const
    {
        return namSinh;
    }

    string getNgayNhanViec() const
    {
        return ngayNhanViec;
    }

    void xuatThongTin() const
    {
        cout << "NhanVien: " << hoTen
             << ", PhongBan: " << phongBan << ", Luong: " << luong
             << ", NamSinh: " << namSinh << ", NgayNhanViec: " << ngayNhanViec << endl;
    }
};

vector<HocVien> danhSachHocVien;
vector<NhanVien> danhSachNhanVien;

void nhapHocVien()
{
    string hoTen;
    double diem1, diem2, diem3;

    cout << "Nhap ho ten hoc vien: ";
    cin.ignore();
    getline(cin, hoTen);
    cout << "Nhap diem 1 (0-10): ";
    cin >> diem1;
    cout << "Nhap diem 2 (0-10): ";
    cin >> diem2;
    cout << "Nhap diem 3 (0-10): ";
    cin >> diem3;

    if (diem1 >= 0 && diem1 <= 10 && diem2 >= 0 && diem2 <= 10 && diem3 >= 0 && diem3 <= 10)
    {
        danhSachHocVien.emplace_back(hoTen, diem1, diem2, diem3);
    }
    else
    {
        cout << "Diem khong hop le. Vui long nhap lai." << endl;
    }
}

void xuatDanhSachHocVien()
{
    for (const auto &hv : danhSachHocVien)
    {
        hv.xuatThongTin();
    }
}

void nhapNhanVien()
{
    string hoTen, phongBan, namSinh, ngayNhanViec;
    int luong;

    cout << "Nhap ho ten nhan vien: ";
    cin.ignore();
    getline(cin, hoTen);
    cout << "Nhap phong ban: ";
    getline(cin, phongBan);
    cout << "Nhap luong: ";
    cin >> luong;
    cin.ignore();
    cout << "Nhap nam sinh (dd/mm/yyyy): ";
    getline(cin, namSinh);
    cout << "Nhap ngay nhan viec (dd/mm/yyyy): ";
    getline(cin, ngayNhanViec);

    danhSachNhanVien.emplace_back(hoTen, phongBan, luong, namSinh, ngayNhanViec);
}

void xuatDanhSachNhanVien()
{
    for (const auto &nv : danhSachNhanVien)
    {
        nv.xuatThongTin();
    }
}

void timHocVienCoTongDiemCaoNhat()
{
    sort(danhSachHocVien.begin(), danhSachHocVien.end(), [](const HocVien &a, const HocVien &b)
         { return a.tinhTongDiem() > b.tinhTongDiem(); });

    for (int i = 0; i < 3 && i < danhSachHocVien.size(); i++)
    {
        danhSachHocVien[i].xuatThongTin();
    }
}

void xuatHocVienDat()
{
    for (const auto &hv : danhSachHocVien)
    {
        if (hv.isDat())
        {
            hv.xuatThongTin();
        }
    }
}

void timNhanVienTheoPhongBan()
{
    string phongBan;
    cout << "Nhap phong ban can tim: ";
    cin.ignore();
    getline(cin, phongBan);

    for (const auto &nv : danhSachNhanVien)
    {
        if (nv.getPhongBan() == phongBan)
        {
            nv.xuatThongTin();
        }
    }
}

void xuatVaTinhTongLuongCNTT()
{
    int tongLuong = 0;
    for (const auto &nv : danhSachNhanVien)
    {
        if (nv.getPhongBan() == "CNTT")
        {
            nv.xuatThongTin();
            tongLuong += nv.getLuong();
        }
    }
    cout << "Tong luong nhan vien phong CNTT: " << tongLuong << endl;
}

void timNhanVienSinhNam2000()
{
    for (const auto &nv : danhSachNhanVien)
    {
        if (nv.getNamSinh().substr(6) == "2000")
        {
            nv.xuatThongTin();
        }
    }
}

void sapXepNhanVienTheoNgayNhanViec()
{
    sort(danhSachNhanVien.begin(), danhSachNhanVien.end(), [](const NhanVien &a, const NhanVien &b)
         { return a.getNgayNhanViec() < b.getNgayNhanViec(); });

    xuatDanhSachNhanVien();
}

void sapXepHocVienTheoTongDiemGiamDan()
{
    sort(danhSachHocVien.begin(), danhSachHocVien.end(), [](const HocVien &a, const HocVien &b)
         { return a.tinhTongDiem() > b.tinhTongDiem(); });

    xuatDanhSachHocVien();
}

int main()
{

    nhapHocVien();
    xuatDanhSachHocVien();
    nhapNhanVien();
    xuatDanhSachNhanVien();
    timHocVienCoTongDiemCaoNhat();
    xuatHocVienDat();
    timNhanVienTheoPhongBan();
    xuatVaTinhTongLuongCNTT();
    timNhanVienSinhNam2000();
    sapXepNhanVienTheoNgayNhanViec();
    sapXepHocVienTheoTongDiemGiamDan();
    return 0;
}