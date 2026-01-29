#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    int b = 1;
    while (n != 0)
    {
        b *= n % 10;
        n /= 10;
    }
    cout << n << endl;
    return 0;
}