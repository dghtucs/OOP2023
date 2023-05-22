#include<bits/stdc++.h>
using namespace std;
const int N = 805;
const int M = 8005;
const int INF = 0x3f3f3f3f;

struct edge {
    int to, nxt, cap;
} e[M * 2];
int head[N], cnt = 1;

void add(int u, int v, int w) {
    e[++cnt] = (edge){v, head[u], w};
    head[u] = cnt;
}

int n, m;
int dep[N], cur[N];

bool bfs() {
    memset(dep, 0, sizeof dep);
    queue<int> q;
    dep[0] = 1;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (dep[v] || !e[i].cap) continue;
            dep[v] = dep[u] + 1;
            if (v == n + 1) return 1;
            q.push(v);
        }
    }
    return 0;
}

int dfs(int u, int flow) {
    if (u == n + 1 || !flow) return flow;
    int rest = flow;
    for (int i = cur[u]; i && rest; i = e[i].nxt) {
        cur[u] = i;
        int v = e[i].to;
        if (dep[v] != dep[u] + 1 || !e[i].cap) continue;
        int k = dfs(v, min(rest, e[i].cap));
        if (!k) dep[v] = 0;
        e[i].cap -= k;
        e[i^1].cap += k;
        rest -= k;
    }
    return flow - rest;
}

int dinic() {
    int flow = 0;
    while (bfs()) {
        memcpy(cur, head, sizeof cur);
        flow += dfs(0, INF);
    }
    return flow;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (i != 0) {
            add(i, n + 1, x);
            add(n + 1, i, 0);
        }
        if (i != n) {
            add(0, i + 1, x);
            add(i + 1, 0, 0);
        }
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        if (w == -1) w = INF;
        add(u, v, w);
        add(v, u, 0);
    }
    printf("%d\n", dinic());
    return 0;
}
