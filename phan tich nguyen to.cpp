#include <bits/stdc++.h>
using namespace std;
int main()
{
    long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        int i = 2;
        while (n != 1)
        {
            while (n % i == 0)
            {
                cout << i << " ";
                n /= i;
            }
            i++;
        }
        cout << endl;
    }
    return 0;
}