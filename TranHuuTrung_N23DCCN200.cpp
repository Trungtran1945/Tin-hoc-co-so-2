// TRAN HUU TRUNG
// MSSV: N23DCCN200
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string n;
    cout << "Nhap so tu nhien n: ";
    cin >> n;
    for (int i = 0; i < n.size(); i++)
    {
        if (n.size() == 1)
        {
            break;
        }
        else if (n[i] > n[i + 1])
        {
            n.erase(i, 1);
            break;
        }
    }
    for (int i = 0; i < n.size(); i++)
    {
        if (n[0] == '0')
        {
            n.erase(0, 1);
        }
    }
    cout << "So nho nhat khi xoa di 1 chu so la: " << n << endl;
    return 0;
}