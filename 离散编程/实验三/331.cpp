#include<bits/stdc++.h>
using namespace std;
const int MAXN = 45;
const int MAXM = 820;
const int INF = 1e9;

struct Edge {
    int v, w, next;
} edges[MAXM];

int n, m, s, t, head[MAXN], cnt = 0;
int dis[MAXN], pre[MAXN], flow[MAXN];

void addEdge(int u, int v, int w) {
    edges[++cnt] = {v, w, head[u]};
    head[u] = cnt;
}

bool bfs() {
    memset(dis, 0, sizeof(dis));
    queue<int> q;
    q.push(s);
    dis[s] = 1;
    flow[s] = INF;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = edges[i].next) {
            int v = edges[i].v;
            if (!dis[v] && edges[i].w > 0) {
                pre[v] = i;
                dis[v] = dis[u] + 1;
                flow[v] = min(flow[u], edges[i].w);
                if (v == t) return true;
                q.push(v);
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v, cuv, fuv;
        cin >> u >> v >> cuv >> fuv;
        addEdge(u, v, cuv - fuv);
        addEdge(v, u, fuv);
    }
    if (!bfs()) {
        cout << "-1\n";
        return 0;
    }
    int minFlow = flow[t];
    vector<int> path;
    for (int i = t; i != s; i = edges[pre[i] ^ 1].v) {
        path.push_back(i);
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    cout << path.size() << " " << minFlow << "\n";
    for (auto v : path) {
        cout << v << " ";
    }
    cout << "\n";
    return 0;
}
