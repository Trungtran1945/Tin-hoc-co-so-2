#include <bits/stdc++.h>
using namespace std;
int Trung, Huu;
int Tran[100] = {0};

void xuat()
{
    for (int j = 1; j <= Huu; j++)
        cout << Tran[j] << " ";
    cout << endl;
}
void Try(int i)
{
    for (int j = Tran[i - 1] + 1; j <= Trung - Huu + i; j++)
    {
        Tran[i] = j;
        if (i == Huu)
        {
            xuat();
        }
        else
            Try(i + 1);
    }
}
int main()
{
    cin >> Trung >> Huu;
    Try(1);
    return 0;
}