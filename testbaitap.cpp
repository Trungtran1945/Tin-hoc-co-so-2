#include <bits/stdc++.h>
using namespace std;
int Tu, Thai, toiuu;
int Truong[100], khoiLuong[100], giaTri[100], luu[100];
int maxKQ = INT_MIN;
void xuat()
{
    int sumKL = 0, sumGT = 0;
    for (int j = 1; j <= Tu; j++)
    {
        cout << Truong[j] << " ";
        sumKL += Truong[j] * khoiLuong[j];
        sumGT += Truong[j] * giaTri[j];
    }
    cout << "| khoi luong: " << sumKL << " gia  tri: " << sumGT;
    if (sumKL <= Thai)
    {
        if (maxKQ < sumGT)
        {
            toiuu = sumKL;
            maxKQ = max(maxKQ, sumGT);
            for (int j = 1; j <= Tu; j++)
                luu[j] = Truong[j];
        }
    }
    cout << endl;
}
void Try(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        Truong[i] = j;
        if (Tu == i)
        {
            xuat();
        }
        else
            Try(i + 1);
    }
}
int main()
{
    fstream TTTT;
    TTTT.open("File.inp", ios::out | ios::in);
    TTTT >> Tu >> Thai;
    toiuu = Thai;
    for (int i = 1; i <= Tu; i++)
    {
        TTTT >> giaTri[i];
        TTTT >> khoiLuong[i];
    }
    Try(1);
    cout << "Phuong phap toi uu: " << endl;
    for (int i = 1; i <= Tu; i++)
        cout << luu[i] << " ";
    cout << "| khoi luong: " << toiuu << " gia tri : " << maxKQ << endl;
    return 0;
}