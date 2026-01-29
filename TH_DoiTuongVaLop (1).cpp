#include <iostream>
#include <string>

using namespace std;

class HocSinh
{
private:
    string mSSV;
    string hoTen;
    float diemTB;

public:
    HocSinh() : mSSV(""), hoTen(""), diemTB(0.0) {}

    void set(string mSSV, string hoTen, float diemTB)
    {
        this->mSSV = mSSV;
        this->hoTen = hoTen;
        this->diemTB = diemTB;
    }

    string getMSSV() const
    {
        return mSSV;
    }

    string getHoTen() const
    {
        return hoTen;
    }

    float getDiemTB() const
    {
        return diemTB;
    }

    void input()
    {
        cout << "Nhap ma so hoc sinh: ";
        cin >> mSSV;
        cout << "Nhap ho va ten hoc sinh: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "Nhap diem trung binh: ";
        cin >> diemTB;
    }

    string rank() const
    {
        if (diemTB >= 8.5)
            return "Gioi";
        else if (diemTB >= 7)
            return "Kha";
        else if (diemTB >= 5)
            return "Trung binh";
        else
            return "Yeu";
    }

    void output() const
    {
        cout << "Ma so hoc sinh: " << mSSV << endl;
        cout << "Ho va ten hoc sinh: " << hoTen << endl;
        cout << "Diem trung binh: " << diemTB << endl;
        cout << "Xep loai : " << rank() << endl;
    }

    void setHoTen(const string &tm)
    {
        hoTen = tm;
    }
};

int main()
{
    HocSinh HS;
    cout << "\tNhap thong tin hoc sinh 1: " << endl;
    HS.input();
    cout << "Thong tin cua hoc sinh: " << endl;
    HS.output();

    string hVT;
    cout << "\tNhap ten moi cua hoc sinh: ";
    cin.ignore();
    getline(cin, hVT);
    HS.setHoTen(hVT);

    cout << "\tThong tin sau khi chinh sua: " << endl;
    HS.output();

    cout << "\tNhap thong tin hoc sinh 2: " << endl;
    HocSinh HS2;
    HS2.input();

    cout << "\tThong tin hoc sinh 2: " << endl;
    HS2.output();

    return 0;
}
