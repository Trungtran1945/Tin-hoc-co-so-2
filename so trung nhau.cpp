#include <iostream>
using namespace std;
void nhap(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void xoa_1_pt(int a[], int &n, int x)
{
    for (int i = x; i < n; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
}
void xoa_phan_tu(int a[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                xoa_1_pt(a, n, j);
                j--;
            }
        }
    }
}
int main()
{
    int a[1000], n;
    cin >> n;
    nhap(a, n);
    xoa_phan_tu(a, n);
    xuat(a, n);
    return 0;
}