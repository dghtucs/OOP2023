#include<bits/stdc++.h>
using namespace std;

const int MAXN = 16;
int n, m, ans = INT_MAX, color[MAXN];
bool graph[MAXN][MAXN], vis[MAXN];

bool valid(int x, int c) {
    for(int i = 1; i <= n; i++) {
        if(graph[x][i] && color[i] == c)
            return false;
    }
    return true;
}

void dfs(int x, int cnt) {
    if(cnt >= ans) return;
    if(x > n) {
        ans = min(ans, cnt);
        return;
    }
    for(int i = 1; i <= cnt; i++) {
        if(valid(x, i)) {
            color[x] = i;
            dfs(x + 1, cnt);
            color[x] = 0;
        }
    }
    color[x] = cnt + 1;
    dfs(x + 1, cnt + 1);
    color[x] = 0;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = true;
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
