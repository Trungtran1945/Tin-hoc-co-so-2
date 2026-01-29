#include <bits/stdc++.h>
using namespace std;

long long UCLN(long long a, long long b)
{
    while (b != 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    long long a, b;
    cin >> a >> b;
    cout << UCLN(a, b) << endl;
    cout << (a * b / UCLN(a, b)) << endl;
    return 0;
}