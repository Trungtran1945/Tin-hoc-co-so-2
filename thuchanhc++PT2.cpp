#include <iostream>
#include <string>
using namespace std;

struct Date
{
    int ngay, thang, nam;
};
class ConNguoi
{
private:
    string hoTen;
    Date birth;

public:
    ConNguoi()
    {
        hoTen = "";
        birth.ngay = 0;
        birth.thang = 0;
        birth.nam = 0;
    }
    ConNguoi(string hoTen, Date birth)
    {
        this->hoTen = hoTen;
        this->birth.ngay = birth.ngay;
        this->birth.thang = birth.thang;
        this->birth.nam = birth.nam;
    }
    string getHoTen()
    {
        return hoTen;
    }
    Date getBirth()
    {
        return birth;
    }
    void setHoTen(string ht)
    {
        hoTen = ht;
    }
    void setBirth(Date b)
    {
        birth.ngay = b.ngay;
        birth.thang = b.thang;
        birth.nam = b.nam;
    }
    void nhap()
    {
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap nam sinh(dd/mm/yyyy): ";
        cin >> birth.ngay;
        cin >> birth.thang;
        cin >> birth.nam;
        cin.ignore();
    }
    void xuat()
    {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Nam sinh: ";
        cout << birth.ngay << "/" << birth.thang << "/" << birth.nam << endl;
    }
};
class HocVien : public ConNguoi
{
private:
    float diem1, diem2, diem3;
    float tongDiem;

public:
    HocVien()
    {
        diem1 = 0.0;
        diem2 = 0.0;
        diem3 = 0.0;
    }
    HocVien(float diem1, float diem2, float diem3)
    {
        this->diem1 = diem1;
        this->diem2 = diem2;
        this->diem3 = diem3;
    }
    float getDiem1()
    {
        return diem1;
    }
    float getDiem2()
    {
        return diem2;
    }
    float getDiem3()
    {
        return diem3;
    }
    void setDiem1(float d1)
    {
        diem1 = d1;
    }
    void setDiem2(float d2)
    {
        diem2 = d2;
    }
    void setDiem3(float d3)
    {
        diem3 = d3;
    }
    float getTongDiem()
    {
        return tongDiem;
    }
    void nhap()
    {
        ConNguoi::nhap();
        do
        {
            cout << "Nhap diem thu 1: ";
            cin >> diem1;
            cin.ignore();
        } while (diem1 < 0 || diem1 > 10);
        do
        {
            cout << "Nhap diem thu 2: ";
            cin >> diem2;
            cin.ignore();
        } while (diem2 < 0 || diem2 > 10);
        do
        {
            cout << "Nhap diem thu 3: ";
            cin >> diem3;
            cin.ignore();
        } while (diem3 < 0 || diem3 > 10);
        tongDiem = diem1 + diem2 + diem3;
    }
    void xuat()
    {
        ConNguoi::xuat();
        cout << "Diem thu 1: " << diem1 << endl;
        cout << "Diem thu 2: " << diem2 << endl;
        cout << "Diem thu 3: " << diem3 << endl;
    }
};
class NhanVien : public ConNguoi
{
private:
    long long luong;
    Date ngayNhanViec;
    string phongBanKhoa;

public:
    NhanVien()
    {
        luong = 0;
        ngayNhanViec.ngay = 0;
        ngayNhanViec.thang = 0;
        ngayNhanViec.nam = 0;
        phongBanKhoa = "";
    }
    NhanVien(float luong, Date ngayNhanViec, string phongBanKhoa)
    {
        this->luong = luong;
        this->ngayNhanViec.ngay = ngayNhanViec.ngay;
        this->ngayNhanViec.thang = ngayNhanViec.thang;
        this->ngayNhanViec.nam = ngayNhanViec.nam;
        this->phongBanKhoa = phongBanKhoa;
    }
    long long getLuong()
    {
        return luong;
    }
    Date getNgayNhanViec()
    {
        return ngayNhanViec;
    }
    string getPhongBanKhoa()
    {
        return phongBanKhoa;
    }
    void setLuong(long long l)
    {
        luong = l;
    }
    void setNgayNhanViec(Date nnv)
    {
        ngayNhanViec.ngay = nnv.ngay;
        ngayNhanViec.thang = nnv.thang;
        ngayNhanViec.nam = nnv.nam;
    }
    void setPhongBanKhoa(string pbk)
    {
        phongBanKhoa = pbk;
    }
    void nhap()
    {
        ConNguoi::nhap();
        cout << "Nhap luong: ";
        cin >> luong;
        cin.ignore();
        cout << "Nhap ngay nhan viec(dd/mm/yyyy): ";
        cin >> ngayNhanViec.ngay;
        cin >> ngayNhanViec.thang;
        cin >> ngayNhanViec.nam;
        cin.ignore();
        cout << "Nhap phong ban khoa: ";
        getline(cin, phongBanKhoa);
    }
    void xuat()
    {
        ConNguoi::xuat();
        cout << "Luong: " << luong << endl;
        cout << "Ngay nhan viec: ";
        cout << ngayNhanViec.ngay << "/" << ngayNhanViec.thang << "/" << ngayNhanViec.nam << endl;
        cout << "Phong ban khoa: " << phongBanKhoa << endl;
    }
};
void timHocVienTong3DiemCaoNhat(HocVien hv[], int slhv)
{
    float max = hv[0].getTongDiem();
    for (int i = 0; i < slhv - 1; i++)
    {
        for (int j = i + 1; j < slhv; j++)
        {
            if (hv[i].getTongDiem() < hv[j].getTongDiem())
            {
                max = hv[j].getTongDiem();
            }
        }
    }
    for (int i = 0; i < slhv; i++)
    {
        if (hv[i].getTongDiem() == max)
        {
            hv[i].xuat();
        }
    }
}
void timHocVienDat(HocVien hv[], int slhv)
{
    for (int i = 0; i < slhv; i++)
    {
        if (hv[i].getDiem1() >= 4 && hv[i].getDiem2() >= 4 && hv[i].getDiem3() >= 4 && hv[i].getTongDiem() >= 15)
        {
            hv[i].xuat();
        }
    }
}
void timNhanVienThuocPhongBan(NhanVien nv[], int slnv, string phongBan)
{
    for (int i = 0; i < slnv; i++)
    {
        if (nv[i].getPhongBanKhoa() == phongBan)
        {
            nv[i].xuat();
        }
    }
}
void xuatDanhSachNhanVienCNTT(NhanVien nv[], int slnv)
{
    long long tongLuong = 0;
    for (int i = 0; i < slnv; i++)
    {
        if (nv[i].getPhongBanKhoa() == "CNTT")
        {
            nv[i].xuat();
            tongLuong += nv[i].getLuong();
        }
    }
    cout << "Tong luong cua nhan vien thuoc phong CNTT: " << tongLuong << endl;
}
void timNhanVienDuocNhanTheoThangNamNhapTuPhim(NhanVien nv[], int slnv, int thang, int nam)
{
    for (int i = 0; i < slnv; i++)
    {
        if (nv[i].getNgayNhanViec().thang == thang && nv[i].getNgayNhanViec().nam == nam)
        {
            nv[i].xuat();
        }
    }
}
void timNhanVienSinhNam2000(NhanVien nv[], int slnv)
{
    for (int i = 0; i < slnv; i++)
    {
        if (nv[i].getBirth().nam == 2000)
        {
            nv[i].xuat();
        }
    }
}
void sapXepDanhSachNhanVienTangDanTheoNNV(NhanVien nv[], int slnv)
{
    for (int i = 0; i < slnv - 1; i++)
    {
        for (int j = i + 1; j < slnv; j++)
        {
            if (nv[i].getNgayNhanViec().nam > nv[j].getNgayNhanViec().nam)
            {
                NhanVien tam = nv[j];
                nv[j] = nv[i];
                nv[i] = tam;
            }
            else if (nv[i].getNgayNhanViec().nam == nv[j].getNgayNhanViec().nam)
            {
                if (nv[i].getNgayNhanViec().thang > nv[j].getNgayNhanViec().thang)
                {
                    NhanVien tam = nv[j];
                    nv[j] = nv[i];
                    nv[i] = tam;
                }
                else if (nv[i].getNgayNhanViec().thang == nv[j].getNgayNhanViec().thang)
                {
                    if (nv[i].getNgayNhanViec().ngay > nv[j].getNgayNhanViec().ngay)
                    {
                        NhanVien tam = nv[j];
                        nv[j] = nv[i];
                        nv[i] = tam;
                    }
                }
            }
        }
    }
    for (int i = 0; i < slnv; i++)
    {
        nv[i].xuat();
    }
}
void sapXepDanhSachHocVienGiamDanTheoTongDiem(HocVien hv[], int slhv)
{
    for (int i = 0; i < slhv - 1; i++)
    {
        for (int j = i + 1; j < slhv; j++)
        {
            if (hv[i].getTongDiem() < hv[j].getTongDiem())
            {
                HocVien tam = hv[i];
                hv[i] = hv[j];
                hv[j] = tam;
            }
        }
    }
    for (int i = 0; i < slhv; i++)
    {
        hv[i].xuat();
    }
}
int main()
{
    int countHV, countNV = 0;
    HocVien hv[1000];
    NhanVien nv[1000];
    while (1)
    {
        int tmp;
        cout << "\tNhan 1 de nhap thong tin hoc vien!" << endl;
        cout << "\tNhan 2 de nhap thong tin nhan vien!" << endl;
        cout << "\tNhan 0 de chuyen sang chuong trinh moi!" << endl;
        cin >> tmp;
        if (tmp == 0)
            break;
        switch (tmp)
        {
        case 1:
            int slhv;
            cout << "Nhap so luong hoc vien: ";
            cin >> slhv;
            cin.ignore();
            for (int i = 0; i < slhv; i++)
            {
                cout << "Nhap thong tin hoc vien thu " << i + 1 << ": " << endl;
                hv[i].nhap();
                countHV++;
            }
            break;
        case 2:
            int slnv;
            cout << "Nhap so luong nhan vien: ";
            cin >> slnv;
            cin.ignore();
            for (int i = 0; i < slnv; i++)
            {
                cout << "Nhap thong tin nhan vien thu " << i + 1 << ": " << endl;
                nv[i].nhap();
                countNV++;
            }
            break;
        default:
            cout << "Vui long nhap hop le theo menu!" << endl;
            break;
        }
    }
    while (1)
    {
        int tmp;
        cout << "\tNhan 1 de xuat thong tin hoc vien!" << endl;
        cout << "\tNhan 2 de xuat thong tin nhan vien!" << endl;
        cout << "\tNhan 3 de tim hoc vien co tong 3 cot diem cao nhat!" << endl;
        cout << "\tNhan 4 de xuat nhung hoc vien dat dieu kien!" << endl;
        cout << "\tNhan 5 de xuat nhan vien nhap phong ban tu ban phim!" << endl;
        cout << "\tNhan 6 de xuat danh sach va tinh tong luong nhan vien thuoc phong CNTT!" << endl;
        cout << "\tNhan 7 de kiem nhan vien duoc nhan vao voi thang nam nhap tu phim!" << endl;
        cout << "\tNhan 8 de kiem nhan vien sinh nam 2000!" << endl;
        cout << "\tNhan 9 de sap xep danh sach nhan vien theo ngay nhan viec!" << endl;
        cout << "\tNhan 10 de sap xep danh sach hoc vien giam dan theo tong diem!" << endl;
        cout << "\tNhan 0 de thoat ra!" << endl;
        cin >> tmp;
        cin.ignore();
        if (tmp == 0)
            break;
        switch (tmp)
        {
        case 1:
            for (int i = 0; i < countHV; i++)
            {
                hv[i].xuat();
            }
            break;
        case 2:
            for (int i = 0; i < countNV; i++)
            {
                nv[i].xuat();
            }
            break;
        case 3:
        {
            timHocVienTong3DiemCaoNhat(hv, countHV);
            break;
        }
        case 4:
        {
            timHocVienDat(hv, countHV);
            break;
        }
        case 5:
        {
            string phongBan;
            cout << "Nhap phong ban can tim: ";
            getline(cin, phongBan);
            cin.ignore();
            timNhanVienThuocPhongBan(nv, countNV, phongBan);
            break;
        }
        case 6:
        {
            xuatDanhSachNhanVienCNTT(nv, countNV);
            break;
        }
        case 7:
            int thang, nam;
            cout << "Nhap thang va nam muon tim kiem: ";
            cin >> thang >> nam;
            timNhanVienDuocNhanTheoThangNamNhapTuPhim(nv, countNV, thang, nam);
            break;
        case 8:
            timNhanVienSinhNam2000(nv, countNV);
            break;
        case 9:
            sapXepDanhSachNhanVienTangDanTheoNNV(nv, countNV);
            break;
        case 10:
            sapXepDanhSachHocVienGiamDanTheoTongDiem(hv, countHV);
            break;
        default:
            cout << "Vui long nhap hop le theo menu!" << endl;
            break;
        }
    }
    return 0;
}