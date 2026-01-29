// #include <iostream>
// using namespace std;
// int trung(int a, int b)
// {
//     if (a == 0)
//     {
//         return b;
//     }
//     else
//     {
//         return trung(a = a % b, b);
//     }
// }
// int main()
// {
//     int a;
//     int b;
//     cin >> a >> b;
//     cout << trung(a, b);
//     return 0;
// }
#include <iostream>

using namespace std;

int sum(int n)
{
    if (n == 0)
        return 0;
    return n + sum(n - 1);
}

int main()
{
    cout << sum(10);
    return 0;
}