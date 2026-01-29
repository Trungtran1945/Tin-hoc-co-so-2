#include <iostream>
using namespace std;
int main()
{
    int n, a;
    cin >> n;
    while (n--)
    {
        cin >> a;
        int socuoi = a % 10;
        int tong = a % 10;
        a /= 10;

        while (a != 0)
        {
            socuoi = a % 10;
            tong += socuoi;
            a /= 10;
        }
        if (tong % 10 == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}