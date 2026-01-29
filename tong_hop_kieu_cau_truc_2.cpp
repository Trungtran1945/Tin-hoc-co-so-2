#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

int
    soLuong = 0,
    soKhach = 0, soSP = 0;

bool kiemTraChu(string s)
{
    for (int i = 0; i < s.size(); i++)
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            continue;
        else
            return 0;
    return 1;
}
bool kiemTraSo(string s)
{
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= '0' && s[i] <= '9')
            continue;
        else
            return 0;
    return 1;
}
class CuaHang
{
private:
    string ma, ten, nhanHieu, mau;
    short size;
    int soLuong;
    int giaBan;

public:
    void set(string ma, string ten, string nhanHieu, string mau, short size, int soLuong, int giaBan)
    {
        this->ma = ma;
        this->ten = ten;
        this->nhanHieu = nhanHieu;
        this->size = size;
        this->soLuong = soLuong;
        this->giaBan = giaBan;
    }
    string getMa()
    {
        return ma;
    }
    string getTen()
    {
        return ten;
    }
    string getNhanHieu()
    {
        return nhanHieu;
    }
    string getMau()
    {
        return mau;
    }
    short getSize()
    {
        return size;
    }
    int getSoLuong()
    {
        return soLuong;
    }
    int getGiaBan()
    {
        return giaBan;
    }
    void input()
    {
        cin.ignore();
        do
        {
            cout << "Ma san pham: ";
            getline(cin, ma);
            if (ma.size() != 6 || !kiemTraChu(ma.substr(0, 2)) || !kiemTraSo(ma.substr(3, 5)))
                cout << "Vui long nhap lai ma san pham gom 6 ki tu! 3 ki tu dau la chu, 3 ki tu sau la so " << endl;
        } while (ma.size() != 6 || !kiemTraChu(ma.substr(0, 2)) || !kiemTraSo(ma.substr(3, 5)));
        do
        {
            cout << "Ten san pham: ";
            getline(cin, ten);
            if (ten.size() > 50)
                cout << "Vui long nhap lai ten san pham khong vuot qua 50 ki tu! " << endl;
        } while (ten.size() > 50);
        do
        {
            cout << "Nhan hieu: ";
            getline(cin, nhanHieu);
            if (nhanHieu.size() > 15)
                cout << "Vui long nhap lai nhan hieu khong vuot qua 15 ki tu! " << endl;
        } while (nhanHieu.size() > 15);
        cout << "Mau san pham: ";
        cin >> mau;
        do
        {
            cout << "Size: ";
            cin >> size;
            if (size < 38 or size > 42)
                cout << "Vui long nhap lai size giay tu 39 den 42! " << endl;
        } while (size < 38 or size > 42);
        do
        {
            cout << "So luong: ";
            cin >> soLuong;
            if (soLuong < 0)
                cout << "Vui long nhap so luong la so nguyen khong am! " << endl;
        } while (soLuong < 0);
        do
        {
            cout << "Gia ban: ";
            cin >> giaBan;
            if (giaBan < 0)
                cout << "Vui long nhap gia ban la so nguyen khong am! " << endl;
        } while (giaBan < 0);
    }
    void output()
    {
        cout << "Ma san pham: " << ma << endl;
        cout << "Ten san pham: " << ten << endl;
        cout << "Nhan hieu: " << nhanHieu << endl;
        cout << "Mau san pham: " << mau << endl;
        cout << "Size: " << size << endl;
        cout << "So luong: " << soLuong << endl;
        cout << "Gia ban: " << giaBan << endl;
    }
};
void nhapGiay(CuaHang &a, int &n)
{
    cout << "-----Nhap doi giay thu " << n + 1 << "-----" << endl;
    a.input();
    n++;
}
void xuatGiay(CuaHang a[], int n)
{
    cout << "----------Danh sach giay----------" << endl;
    if (n == 0)
        cout << "Danh sach trong!" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "    -Doi giay thu " << i + 1 << "-" << endl;
        a[i].output();
    }
}
void timMaSanPham(CuaHang a[], int n)
{
    string k;
    int cnt = 0;
    if (soLuong == 0)
    {
        cout << "Danh sach trong!" << endl;
        return;
    }
    cout << "Nhap ma san pham can tim: ";
    cin >> k;
    for (int i = 0; i < n; i++)
        if (a[i].getMa() == k)
        {
            a[i].output();
            cnt++;
        }
    if (cnt == 0)
        cout << "Khong co ma giay can tim!" << endl;
}
void suaTTGiay(CuaHang a[], int n)
{
    string k;
    int cnt = 0;
    if (soLuong == 0)
    {
        cout << "Danh sach trong!" << endl;
        return;
    }
    cout << "Nhap ma giay can de sua: ";
    cin.ignore();
    getline(cin, k);
    for (int i = 0; i < n; i++)
        if (a[i].getMa() == k)
        {
            a[i].input();
            cnt++;
        }
    if (cnt == 0)
        cout << "Khong co ma giay can sua!" << endl;
}
void timTenSanPham(CuaHang a[], int n)
{
    string k;
    int cnt = 0;
    if (soLuong == 0)
    {
        cout << "Danh sach trong!" << endl;
        return;
    }
    cout << "Nhap ten san pham can tim: ";
    cin >> k;
    for (int i = 0; i < n; i++)
        if (a[i].getTen() == k)
        {
            a[i].output();
            cnt++;
        }
    if (cnt == 0)
        cout << "Khong co ten giay can tim!" << endl;
}
void timSanPham(CuaHang a[], int n)
{
    string nhanHieu, mau;
    short size;
    int cnt = 0;
    if (soLuong == 0)
    {
        cout << "Danh sach trong!" << endl;
        return;
    }
    cout << "Nhap nhan hieu san pham can tim: ";
    getline(cin, nhanHieu);
    cout << "Nhap mau san phan cam tim: ";
    cin >> mau;
    cout << "Nhap co size san pham can tim: ";
    cin >> size;
    for (int i = 0; i < n; i++)
        if (a[i].getNhanHieu() == nhanHieu && a[i].getMau() == mau && a[i].getSize() == size)
        {
            a[i].output();
            cnt++;
        }
    if (cnt == 0)
        cout << "Khong co doi giay can tim!" << endl;
}
void demSLGiay(CuaHang a[], int n)
{
    string k;
    int dem39 = 0, dem40 = 0, dem41 = 0, dem42 = 0;
    if (soLuong == 0)
    {
        cout << "Danh sach trong!" << endl;
        return;
    }
    cout << "Nhap nhan hieu giay can dem: ";
    getline(cin, k);
    for (int i = 0; i < n; i++)
        if (k == a[i].getNhanHieu())
            switch (a[i].getSize())
            {
            case 39:
                dem39 += a[i].getSoLuong();
                break;
            case 40:
                dem40 += a[i].getSoLuong();
                break;
            case 41:
                dem41 += a[i].getSoLuong();
                break;
            case 42:
                dem42 += a[i].getSoLuong();
                break;
            }
    if (dem39 != 0)
        cout << "Co " << dem39 << " doi giay size 39 thuoc nhan hieu " << k << endl;
    else
        cout << "Khong co doi giay size 39 thuoc nhan hieu " << k << endl;
    if (dem40 != 0)
        cout << "Co " << dem40 << " doi giay size 40 thuoc nhan hieu " << k << endl;
    else
        cout << "Khong co doi giay size 40 thuoc nhan hieu " << k << endl;
    if (dem41 != 0)
        cout << "Co " << dem41 << " doi giay size 41 thuoc nhan hieu " << k << endl;
    else
        cout << "Khong co doi giay size 41 thuoc nhan hieu " << k << endl;
    if (dem42 != 0)
        cout << "Co " << dem42 << " doi giay size 42 thuoc nhan hieu " << k << endl;
    else
        cout << "Khong co doi giay size 42 thuoc nhan hieu " << k << endl;
}
void xoaGiay(CuaHang a[], int &n)
{
    string k;
    int cnt = 0;
    if (soLuong == 0)
    {
        cout << "Danh sach trong!" << endl;
        return;
    }
    cout << "Nhap ma san pham can xoa: ";
    cin.ignore();
    getline(cin, k);
    for (int i = 0; i < n; i++)
        if (a[i].getMa() == k)
        {
            for (int j = i; j < n - 1; j++)
                a[i] = a[i + 1];
            n--;
            cnt++;
        }
    if (cnt == 0)
        cout << "Khong co thong tin ma san pham can xoa! " << endl;
    else
        cout << "Xoa thanh cong! ";
}
void sapxepDSGiay(CuaHang a[], int n)
{
    if (soLuong == 0)
    {
        cout << "Danh sach trong!" << endl;
        return;
    }
    cout << "Nhap ma san pham can xoa: ";
    sort(a, a + n, [&](CuaHang i, CuaHang j)
         { if (i.getNhanHieu() == j.getNhanHieu()) 
                return i.getSoLuong() < j.getSoLuong();
           else 
                return i.getNhanHieu()<j.getNhanHieu(); });
    cout << "Sap xep xong!" << endl;
}
void timSL(CuaHang a[], int n)
{
    if (soLuong == 0)
    {
        cout << "Danh sach trong!" << endl;
        return;
    }
    int k, cnt = 0;
    cout << "Nhap vao mot so: ";
    cin >> k;
    cout << "Nhugn doi giay co so luong be hon " << k << ": " << endl;
    for (int i = 0; i < n; i++)
        if (a[i].getSoLuong() < k)
        {
            a[i].output();
            cnt++;
        }
    if (cnt == 0)
        cout << "Khong co doi giay nao co so luong be hon " << k << endl;
}
void nextWork()
{
    cout << "Nhap mot phim bat ki de tiep tuc!";
    getch();
    // cout << "\x1B[2J\x1B[H";
    system("cls");
}
class KhachHang
{
private:
    string maKH, tenKH, sDT;
    string dChi;

public:
    void set(string maKH, string tenKH, string sDT, string dChi)
    {
        this->maKH = maKH;
        this->tenKH = tenKH;
        this->sDT = sDT;
        this->dChi = dChi;
    }
    string getMaKH()
    {
        return maKH;
    }
    string getTenHK()
    {
        return tenKH;
    }
    string getSDT()
    {
        return sDT;
    }
    string getDChi()
    {
        return dChi;
    }
    void input()
    {
        cin.ignore();
        do
        {
            cout << "Nhap ma khach hang: ";
            getline(cin, maKH);
            if (maKH.size() != 4 || !kiemTraChu(maKH.substr(0, 1)) || !kiemTraSo(maKH.substr(2, 3)))
                cout << "Vui long nhap ma khach hang gom 4 ki tu! 2 ki tu dau la chu, 2 ki tu sau la so " << endl;
        } while (maKH.size() != 4 || !kiemTraChu(maKH.substr(0, 1)) || !kiemTraSo(maKH.substr(2, 3)));
        do
        {
            cout << "Ten khach hang: ";
            getline(cin, tenKH);
            if (tenKH.size() > 50)
                cout << "Vui long nhap lai ten khach hang khong vuot qua 50 ki tu! " << endl;
        } while (tenKH.size() > 50);
        do
        {
            cout << "So dien thoai: ";
            getline(cin, sDT);
            if (sDT.size() != 10 || !kiemTraSo(sDT.substr(0, 9)))
                cout << "Vui long nhap lai so dien thoai gom 10 ki tu! " << endl;
        } while (sDT.size() != 10 || !kiemTraSo(sDT.substr(0, 9)));
        cout << "Dia chi: ";
        getline(cin, dChi);
    }
    void output()
    {
        cout << "Ma khach hang: " << maKH << endl;
        cout << "Ten khach hang: " << tenKH << endl;
        cout << "So dien thoai: " << sDT << endl;
        cout << "Dia chi: " << dChi << endl;
    }
};
void nhapKhachHang(KhachHang &a, int &n)
{
    cout << "\tNhap khach hang thu " << n + 1 << endl;
    a.input();
    n++;
}
void xuatDSKH(KhachHang a[], int n)
{
    cout << "----------Danh sach khach hang----------" << endl;
    if (n == 0)
        cout << "Danh sach trong!" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "    -Khach hang thu " << i + 1 << "-" << endl;
        a[i].output();
    }
}
bool kiemTraSoSP(string s)
{
    short arr[10] = {0};
    for (int i = 0; i < s.size() - 1; i++)
        if (s[i] > s[i + 1])
            return 0;
    for (int i = 0; i < s.size(); i++)
    {
        arr[s[i] - '0']++;
        if (arr[s[i] - '0'] > 1)
            return 0;
    }
    return 1;
}
class ThongTinMuaHang
{
public:
    string maSP;
    int sL;
    long tien;
    void set(string maSP, int sL, long tien)
    {
        this->maSP = maSP;
        this->sL = sL;
        this->tien = tien;
    }
    string getMaSP()
    {
        return maSP;
    }
    int getSL()
    {
        return sL;
    }
    long getTien()
    {
        return tien;
    }
    void input()
    {
        cin.ignore();
        do
        {
            cout << "Ma san pham: ";
            getline(cin, maSP);
            if (maSP.size() != 4 || !kiemTraSo(maSP.substr(1, 3)) || !kiemTraSoSP(maSP.substr(1, 3)))
                cout << "Vui long nhap lai ma san pham gom 4 ki tu! Co dang la Gxxx voi xxx la 3 ky tu tang dan, khong trung nhau" << endl;
        } while (maSP.size() != 4 || !kiemTraSo(maSP.substr(1, 3)) || !kiemTraSoSP(maSP.substr(1, 3)));
        cout << "So luong: ";
        cin >> sL;
        cout << "Tong tien: ";
        cin >> tien;
    }
    void output()
    {
        cout << "Ma san pham: " << maSP << endl;
        cout << "So luong: " << sL << endl;
        cout << "Tong tien: " << tien << endl;
    }
    friend class KhachHang;
};
void nhapSP(ThongTinMuaHang &a, int &n)
{
    cout << "\tNhap khach hang thu " << n + 1 << " can mua: " << endl;
    a.input();
    n++;
}
void xuatDSMH(ThongTinMuaHang a[], int n)
{
    cout << "----------Danh sach mua hang----------" << endl;
    if (n == 0)
        cout << "Danh sach trong!" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "    -Khach hang thu " << i + 1 << " can mua-" << endl;
        a[i].output();
    }
}
int main()
{
    CuaHang Giay[250];
    KhachHang Khach[250];
    ThongTinMuaHang SP[250];

    while (1)
    {
        cout << setfill(' ') << setw(58) << "MENU" << endl;
        cout << setfill(' ') << setw(25) << "SAN PHAM" << setfill(' ') << setw(70) << "KHACH HANG" << endl;
        cout << "a: Nhap thong tin giay" << setfill(' ') << setw(67) << "k: Nhap thong tin khach hang" << endl;
        cout << "b: Xuat danh sach giay" << setfill(' ') << setw(77) << "l: Xuat danh sach thong tin khach hang" << endl;
        cout << "c: Tim theo ma giay" << setfill(' ') << setw(87) << "m: Nhap thong tin san pham khach hang can mua" << endl;
        cout << "d: Sua thong tin giay theo ma" << setw(91) << "n: (Tu them vao) Xuat thong tin san pham khach hang can mua" << endl;
        cout << "e: Xoa giay theo ma san pham" << endl;
        cout << "f: Tim giay theo ten" << endl;
        cout << "g: Tim giay theo nhan hieu, size va mau sac" << endl;
        cout << "h: Dem so luong size giay cua mot nhan hieu" << endl;
        cout << "i: Sap xep cac giay theo nhan hieu" << endl;
        cout << "j: Tim nhung doi giay co so luong nho hon mot so nhap vao" << endl;
        cout << setfill(' ') << setw(109) << "p: Exit" << endl;
        cout << endl;
        char ch;
        cout << "Nhap cong viec can lam: ";
        cin >> ch;
        switch (ch)
        {
        case 'a':
            nhapGiay(Giay[soLuong], soLuong);
            nextWork();
            break;
        case 'b':
            xuatGiay(Giay, soLuong);
            nextWork();
            break;
        case 'c':
            timMaSanPham(Giay, soLuong);
            nextWork();
            break;
        case 'd':
            suaTTGiay(Giay, soLuong);
            nextWork();
            break;
        case 'e':
            xoaGiay(Giay, soLuong);
            nextWork();
            break;
        case 'f':
            timTenSanPham(Giay, soLuong);
            nextWork();
            break;
        case 'g':
            timSanPham(Giay, soLuong);
            nextWork();
            break;
        case 'h':
            demSLGiay(Giay, soLuong);
            nextWork();
            break;
        case 'i':
            sapxepDSGiay(Giay, soLuong);
            nextWork();
            break;
        case 'j':
            timSL(Giay, soLuong);
            nextWork();
            break;
        case 'k':
            nhapKhachHang(Khach[soKhach], soKhach);
            nextWork();
            break;
        case 'l':
            xuatDSKH(Khach, soKhach);
            nextWork();
            break;
        case 'm':
            nhapSP(SP[soSP], soSP);
            nextWork();
            break;
        case 'n':
            xuatDSMH(SP, soSP);
            nextWork();
            break;
        case 'p':
            cout << "Xin cam on!" << endl;
            return 0;
        default:
            break;
        }
    }
    return 1;
}