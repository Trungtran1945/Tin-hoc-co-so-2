#include <bits/stdc++.h>
using namespace std;
int Trung;
int Tran[100];
bool N23[100];
void xuat()
{
    for (int j = 1; j <= Trung; j++)
        cout << Tran[j] << " ";
    cout << endl;
}
void Try(int i)
{
    for (int j = 1; j <= Trung; j++)
        if (N23[j] == true)
        {
            N23[j] = false;
            Tran[i] = j;
            if (Trung == i)
            {
                xuat();
            }
            else
                Try(i + 1);
            N23[j] = true;
        }
}
int main()
{
    cin >> Trung;
    for (int i = 1; i <= Trung; i++)
        N23[i] = true;
    Try(1);
    return 0;
}