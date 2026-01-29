#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void findPrimeFactors(long long n)
{

    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n /= 2;
    }

    for (long long i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n /= i;
        }
    }

    if (n > 2)
    {
        cout << n;
    }
    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long N;
        cin >> N;

        findPrimeFactors(N);
    }

    return 0;
}