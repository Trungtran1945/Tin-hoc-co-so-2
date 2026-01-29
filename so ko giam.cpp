#include <bits/stdc++.h>
using namespace std;
bool check(string x)
{
    for (int i = 0; i < x.length() - 1; i++)
    {
        if (x[i] > x[i + 1])
            return false;
    }
    return true;
}
int main()
{
    long t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cin.ignore();
        cout << (check(s) ? "YES" : "NO") << endl;
    }
    return 0;
}