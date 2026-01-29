#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct Shoe
{
    string productID;
    string name;
    string brand;
    string color;
    string size;
    int quantity;
};

string generateProductID(int index)
{
    stringstream ss;
    ss << index;
    string indexStr = ss.str();
    return "G" + string(3 - indexStr.length(), '0') + indexStr;
}

bool isProductIDUnique(const vector<Shoe> &shoes, const string &productID)
{
    for (size_t i = 0; i < shoes.size(); ++i)
    {
        if (shoes[i].productID == productID)
        {
            return false;
        }
    }
    return true;
}

void addShoe(vector<Shoe> &shoes, int &index)
{
    Shoe shoe;

    shoe.productID = generateProductID(index);
    index++;

    cout << "Nhap ten san pham: ";
    cin.ignore();
    getline(cin, shoe.name);

    cout << "Nhap nhan hieu: ";
    getline(cin, shoe.brand);

    cout << "Nhap mau sac (Den, Trang, Xam, Xanh, Hong): ";
    getline(cin, shoe.color);

    cout << "Nhap size (39-42): ";
    cin >> shoe.size;

    cout << "Nhap so luong: ";
    cin >> shoe.quantity;

    shoes.push_back(shoe);
    cout << "Them san pham thanh cong voi ma san pham: " << shoe.productID << endl;
}

void displayShoe(const Shoe &shoe)
{
    cout << "Ma san pham: " << shoe.productID << endl;
    cout << "Ten san pham: " << shoe.name << endl;
    cout << "Nhan hieu: " << shoe.brand << endl;
    cout << "Mau sac: " << shoe.color << endl;
    cout << "Size: " << shoe.size << endl;
    cout << "So luong: " << shoe.quantity << endl;
}

void displayShoeList(const vector<Shoe> &shoes)
{
    if (shoes.empty())
    {
        cout << "Danh sach giay trang." << endl;
    }
    else
    {
        for (size_t i = 0; i < shoes.size(); ++i)
        {
            displayShoe(shoes[i]);
            cout << "-------------------------" << endl;
        }
    }
}

int findShoeByProductID(const vector<Shoe> &shoes, const string &productID)
{
    for (int i = 0; i < shoes.size(); i++)
    {
        if (shoes[i].productID == productID)
        {
            return i;
        }
    }
    return -1;
}

void updateShoeByProductID(vector<Shoe> &shoes, const string &productID)
{
    int index = findShoeByProductID(shoes, productID);
    if (index == -1)
    {
        cout << "Khong tim thay san pham voi ma " << productID << endl;
        return;
    }

    cout << "Sua thong tin giay (ma: " << productID << ")\n";
    cout << "Nhap ten san pham moi: ";
    cin.ignore();
    getline(cin, shoes[index].name);

    cout << "Nhap nhan hieu moi: ";
    getline(cin, shoes[index].brand);

    cout << "Nhap mau sac moi: ";
    getline(cin, shoes[index].color);

    cout << "Nhap size moi: ";
    cin >> shoes[index].size;

    cout << "Nhap so luong moi: ";
    cin >> shoes[index].quantity;

    cout << "Sua thong tin san pham thanh cong.\n";
}

void deleteShoeByProductID(vector<Shoe> &shoes, const string &productID)
{
    int index = findShoeByProductID(shoes, productID);
    if (index == -1)
    {
        cout << "Khong tim thay san pham voi ma " << productID << endl;
        return;
    }

    shoes.erase(shoes.begin() + index);
    cout << "Xoa san pham thanh cong.\n";
}

int main()
{
    vector<Shoe> shoes;
    int productIDIndex = 1;
    int choice;

    do
    {
        cout << "\nChuong trinh quan ly giay the thao\n";
        cout << "1. Them giay moi\n";
        cout << "2. Hien thi danh sach giay\n";
        cout << "3. Tim giay theo ma san pham\n";
        cout << "4. Sua giay theo ma san pham\n";
        cout << "5. Xoa giay theo ma san pham\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addShoe(shoes, productIDIndex);
            break;
        case 2:
            displayShoeList(shoes);
            break;
        case 3:
        {
            string productID;
            cout << "Nhap ma san pham can tim: ";
            cin >> productID;
            int index = findShoeByProductID(shoes, productID);
            if (index != -1)
            {
                displayShoe(shoes[index]);
            }
            else
            {
                cout << "Khong tim thay san pham voi ma " << productID << endl;
            }
            break;
        }
        case 4:
        {
            string productID;
            cout << "Nhap ma san pham can sua: ";
            cin >> productID;
            updateShoeByProductID(shoes, productID);
            break;
        }
        case 5:
        {
            string productID;
            cout << "Nhap ma san pham can xoa: ";
            cin >> productID;
            deleteShoeByProductID(shoes, productID);
            break;
        }
        case 0:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    } while (choice != 0);

    return 0;
}
