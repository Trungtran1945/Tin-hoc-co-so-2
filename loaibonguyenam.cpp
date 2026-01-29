#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    string tam = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            tam += (s[i] + 32);
        }
        else
        {
            tam += s[i];
        }
    }
    string result = "";
    for (int i = 0; i < tam.length(); i++)
    {
        if (tam[i] != 'a' && tam[i] != 'e' && tam[i] != 'i' && tam[i] != 'o' && tam[i] != 'u' && tam[i] != 'y')
        {
            result += '.';
            result += tam[i];
        }
    }
    cout << result;
    return 0;
}