#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    set<int> beautiful_number = {2, 3, 5, 11, 17, 23, 41, 53, 67, 71, 101, 107, 113, 131, 139, 157, 193, 229, 233, 251, 283, 311, 337, 373, 401, 409, 431, 463, 503, 521, 571, 607, 643, 661, 701, 733, 751, 823};
    if (a > b)
        swap(a, b);
    for (auto i = a; i <= b; i++)
        if (beautiful_number.find(i) != beautiful_number.end())
            cout << i << " ";
    return 0;
}