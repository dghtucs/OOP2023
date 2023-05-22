
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1005;

vector<int> graph[MAXN];
int color[MAXN];

void dfs(int u) {
    vector<bool> used(MAXN, false);
    for (int v : graph[u]) {
        if (color[v]) used[color[v]] = true;
    }
    for (int c = 1; ; c++) {
        if (!used[c]) {
            color[u] = c;
            break;
        }
    }
    for (int v : graph[u]) {
        if (!color[v]) dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        if (!color[i]) dfs(i);
    }

    int maxColor = 0;
    for (int i = 1; i <= N; i++) {
        maxColor = max(maxColor, color[i]);
    }
    cout << maxColor << "\n";
    for (int i = 1; i <= N; i++) {
        cout << color[i] << " ";
    }
    cout << "\n";
    return 0;
}
