#include <bits/stdc++.h>
using namespace std;

int a[100][100], chuaxet[100], truoc[100], n, s, t;

void init()
{
    ifstream fp("dothi.txt");
    fp >> n;
    for (int i = 1; i <= n; i++)
    {
        chuaxet[i] = 1;
        for (int j = 1; j <= n; j++)
        {
            fp >> a[i][j];
        }
    }
    fp.close();
}
void DFSstack(int x)
{
    stack<int> nganxep;
    nganxep.push(x);
    chuaxet[x] = 0;
    while (!nganxep.empty())
    {
        int u = nganxep.top();
        nganxep.pop();
        for (int v = 1; v <= n; v++)
        {
            if (a[u][v] && chuaxet[v])
            {
                chuaxet[v] = 0;
                nganxep.push(u);
                nganxep.push(v);
                truoc[v] = u;
                break;
            }
        }
    }
}
void BFS(int x)
{
    queue<int> hangdoi;
    hangdoi.push(x);
    chuaxet[x] = 0;
    while (!hangdoi.empty())
    {
        int u = hangdoi.front();
        hangdoi.pop();
        for (int v = 1; v <= n; v++)
        {
            if (a[u][v] && chuaxet[v])
            {
                hangdoi.push(v);
                chuaxet[v] = 0;
                truoc[v] = u;
            }
        }
    }
}
void ReInit()
{
    for (int i = 1; i <= n; i++)
    {
        chuaxet[i] = 1;
    }
}
void duongdi()
{
    if (truoc[t] == 0)
    {
        cout << "Khong ton tai duong di tu " << s << " den " << t << endl;
    }
    else
    {
        cout << t << " <- ";
        int u = truoc[t];
        while (u != s)
        {
            cout << u << " <- ";
            u = truoc[u];
        }
        cout << s << endl;
    }
}
int main()
{
    init();
    cout << "Dinh dau: ";
    cin >> s;
    cout << "Dinh cuoi: ";
    cin >> t;

    cout << "Duong di theo DFS: ";
    DFSstack(s);
    duongdi();

    cout << endl;

    ReInit();

    cout << "Duong di theo BFS: ";
    BFS(s);
    duongdi();
    return 0;
}