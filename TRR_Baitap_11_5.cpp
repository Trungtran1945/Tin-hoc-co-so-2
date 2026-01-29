#include <bits/stdc++.h>
using namespace std;
int Trung;
int Tran[100];
void xuat()
{
    for (int j = 1; j <= Trung; j++)
        cout << Tran[j] << " ";
    cout << endl;
}
void Try(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        Tran[i] = j;
        if (Trung == i)
        {
            xuat();
        }
        else
            Try(i + 1);
    }
}
int main()
{
    cin >> Trung;
    Try(1);
    return 0;
}

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