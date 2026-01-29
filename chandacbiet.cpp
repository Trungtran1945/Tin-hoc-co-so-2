#include <bits/stdc++.h>
using namespace std;
bool Check(unsigned long long x)
{
    if (x % 2 != 0)
        return false;
    while (x != 0)
    {
        int tmp = x % 10;
        if (tmp % 2 != 0)
            return false;
        x /= 10;
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        unsigned long long n;
        cin >> n;
        cout << (Check(n) ? "YES" : "NO") << endl;
    }
    return 0;
}