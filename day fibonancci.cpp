#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long a = 0, b = 1;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        cout << a << " ";
        m = a;
        a = b;
        b = m + a;
    }
    return 0;
}