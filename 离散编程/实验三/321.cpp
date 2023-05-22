#include<bits/stdc++.h>
using namespace std;

const int MAXN = 15;
int dp[(1<<MAXN)+10],g[MAXN+10][MAXN+10],n,m;

int main() {
    cin >> n >> m;
    memset(g,0,sizeof(g));
    for (int i=1;i<=m;i++) {
        int u,v;
        cin >> u >> v;
        u--; v--; // 0-indexed
        g[u][v] = g[v][u] = 1;
    }
    for (int i=0;i<n;i++) g[i][i] = 1;
    for (int i=0;i<(1<<n);i++) {
        int j = 0;
        while (j<n) {
            if ((i>>j)&1) {
                for (int k=0;k<n;k++)
                    if (((i>>k)&1) && !g[j][k]) goto next;
            }
            j++;
        }
        dp[i] = 1;
        next:;
    }
    for (int i=0;i<(1<<n);i++)
        if (!dp[i])
            for (int j=i;j;j=(j-1)&i)
                if (dp[j] && dp[i^j]) dp[i] = max(dp[i],dp[j] + dp[i^j]);
    cout << dp[(1<<n)-1] << endl;
    return 0;
}
