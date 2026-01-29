#include <iostream>
using namespace std;
int main()
{
    int b;
    cin >> b;

    while (b--)
    {
        string n;
        cin >> n;
        for (int i = 0; i < n.size(); i++)
        {
            if (n[i] >= 'A' && n[i] <= 'Z')
            {
                n[i] += 32;
            }
            else
            {
                n[i] -= 32;
            }
        }
        cout << n << endl;
    }

    return 0;
}