#include <iostream>
using namespace std;

int main()
{
    int so;
    int soTemp;
    int tong = 0;

    cin >> so;
    soTemp = so;
    while (soTemp != 0)
    {
        tong += soTemp % 10;
        soTemp /= 10;
    }
    cout << tong << endl;
    return 0;
}