#include<bits/stdc++.h>
using namespace std;

const int MAXN = 16;
const int INF = 1e9;

vector<int> graph[MAXN];
int dp[1 << MAXN], color[MAXN];
int N, M;

int dfs(int state) {
    if(dp[state] != -1)
        return dp[state];
    dp[state] = INF;
    int temp[MAXN];
    for(int c = 1; c <= N; c++) {
        bool flag = true;
        for(int i = 0; i < N; i++) {
            if((state >> i) & 1) {
                for(int j : graph[i]) {
                    if(color[j] == c) {
                        flag = false;
                        break;
                    }
                }
                if(!flag)
                    break;
            }
        }
        if(flag) {
            for(int i = 0; i < N; i++) {
                if((state >> i) & 1) {
                    color[i] = c;
                }
            }
            memcpy(temp, color, sizeof(color)); // Save the color state
            dp[state] = min(dp[state], dfs(state - (1 << __builtin_ctz(state))) + 1);
            memcpy(color, temp, sizeof(color)); // Restore the color state
        }
    }
    return dp[state];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    int ans = dfs((1 << N) - 1);
    cout << ans << "\n";

    for(int i = 0; i < N; i++) {
        for(int j = 1; j <= ans; j++) {
            bool flag = true;
            for(int k : graph[i]) {
                if(color[k] == j) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
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
