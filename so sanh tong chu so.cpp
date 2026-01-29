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
    long a, b;
    cin >> a >> b;
    if (sum(a) <= sum(b))
        cout << a << " " << b;
    else
        cout << b << " " << a;
    return 0;
}