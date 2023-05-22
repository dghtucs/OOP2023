#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MAXN = 16;
int g[MAXN][MAXN]; // adjacency matrix
int color[MAXN]; // color assignment for each node
int dp[1 << MAXN]; // dp array for state compression
int N, M; // number of nodes and edges

int dfs(int state) {
    if(dp[state] != -1) return dp[state];
    dp[state] = INF;
    for(int c = 1; c <= N; c++) {
        bool valid = true;
        for(int i = 0; i < N; i++) {
            if((state >> i) & 1) {
                if(g[i][c]) {
                    valid = false;
                    break;
                }
            }
        }
        if(valid) {
            for(int i = 0; i < N; i++) {
                if((state >> i) & 1) g[i][c] = 1;
            }
            dp[state] = min(dp[state], dfs(state - (1 << __builtin_ctz(state))) + 1);
            for(int i = 0; i < N; i++) {
                if((state >> i) & 1) g[i][c] = 0;
            }
        }
    }
    return dp[state];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ifstream cin("in.txt");
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u][v] = g[v][u] = 1;
    }

    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    int res = dfs((1 << N) - 1);
    cout << res << "\n";

    for(int i = 0; i < N; i++) {
        for(int j = 1; j <= res; j++) {
            bool valid = true;
            for(int k = 0; k < N; k++) {
                if(g[i][k] && color[k] == j) {
                    valid = false;
                    break;
                }
            }
            if(valid) {
                color[i] = j;
                break;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        cout << color[i] << " ";
    }
    cout << "\n";

    return 0;
}
