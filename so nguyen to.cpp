#include <bits/stdc++.h>
using namespace std;
bool nt(long long m)
{
    long i1, b1 = trunc(sqrt(m));
    if (m == 2 || m == 3)
        return 1;
    if (m % 2 == 0 || m % 3 == 0 || m < 2)
        return 0;
    for (i1 = 5; i1 <= b1; i1 += 6)
        if (m % i1 == 0 || m % (i1 + 2) == 0)
            return 0;
    return 1;
}
int main()
{
    long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << (nt(n) ? "YES" : "NO") << endl;
    }
    return 0;
}