#include <iostream>
#include <cstring>
#include <algorithm>
#include<fstream>

using namespace std;

const int N = 20, M = 110;

int n, m;
int g[N][N];
int f[N];
int ans[N];

bool dfs(int u, int limit)
{
    if (u == n + 1) return true;

    for (int i = 1; i <= limit; i ++ )
    {
        bool flag = true;
        for (int j = 1; j < u; j ++ )
            if (g[j][u] && f[j] == i)
            {
                flag = false;
                break;
            }
        if (flag)
        {
            f[u] = i;
            if (dfs(u + 1, limit)) return true;
        }
    }

    return false;
}

int main()
{
    ifstream cin("in.txt");
    cin >> n >> m;
    while (m -- )
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }

    for (int i = 1; i <= n; i ++ )
    {
        f[i] = 1;
        if (!dfs(1, i)) break;
        memcpy(ans, f, sizeof f);
    }

    cout << *max_element(ans + 1, ans + n + 1) << endl;
    for (int i = 1; i <= n; i ++ ) cout << ans[i] << ' ';
    cout << endl;

    return 0;
}
