#include<bits/stdc++.h>
using namespace std;

typedef pair<long long, int> pli;

const int MAXN = 3005;
int x[MAXN], y[MAXN], visited[MAXN];
long long dis[MAXN];
vector<pli> g[MAXN];

long long dist(int i, int j) {
    return pow(abs(x[i] - x[j]), 3) + pow(abs(y[i] - y[j]), 3);
}

void add_edge(int u, int v, long long w) {
    g[u].push_back(make_pair(w, v));
    g[v].push_back(make_pair(w, u));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            add_edge(i, j, dist(i, j));
        }
    }
    
    for(int i = 0; i < n; i++) {
        dis[i] = LLONG_MAX;
    }

    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dis[0] = 0;
    pq.push(make_pair(0, 0));
    long long res = 0;
    
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if(visited[u]) continue;
        visited[u] = 1;
        res += dis[u];
        for(auto e : g[u]) {
            int v = e.second;
            long long w = e.first;
            if(!visited[v] && w < dis[v]) {
                dis[v] = w;
                pq.push(make_pair(w, v));
            }
        }
    }

    cout << res << "\n";

    return 0;
}
