#include <bits/stdc++.h>
using namespace std;
long long sum(long long x)
{
    long long sumt = 0;
    while (x != 0)
    {
        sumt += x % 10;
        x /= 10;
    }
    return sumt;
}
int main()
{
    long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << sum(n) << endl;
    }
    return 0;
}
