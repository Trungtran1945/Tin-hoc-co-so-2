#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n != 0)
    {
        long long a;
        long long b = 0;
        cin >> a;
        b = a * (a + 1) / 2;
        cout << b << endl;
        n--;
    }
    return 0;
}