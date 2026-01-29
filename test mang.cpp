#include <iostream>
using namespace std;
void nhap(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void tong(int a[], int n)
{
    int b = 0;
    for (int i = 0; i < n; i++)
    {
        b = b + a[i];
    }
    cout << b << endl;
}
int main()
{
    int a[1000], n;
    cin >> n;
    nhap(a, n);
    tong(a, n);
    return 0;
}