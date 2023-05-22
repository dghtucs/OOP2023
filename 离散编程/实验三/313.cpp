#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
typedef long long ll;

struct edge {
    int u, v;
    ll w;
    bool operator<(const edge& rhs) const {
        return w > rhs.w;
    }
};

int x[N], y[N], par[N];
pair<int, int> e[N];
priority_queue<edge> pq;

int find(int x) {
    if (x < 0 || x >= N) {
        return -1; // Avoid segmentation fault
    }
    return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != -1 && fy != -1) {
        par[fx] = fy;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        par[i] = i;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            ll dist = abs(x[i] - x[j]);
            dist = dist * dist * dist;
            ll disty = abs(y[i] - y[j]);
            dist += disty * disty * disty;
            pq.push({i, j, dist});
        }
    }
    for(int i = 1; i <= q; i++) {
        cin >> e[i].first >> e[i].second;
        ll c;
        cin >> c;
        pq.push({e[i].first, e[i].second, c});
    }
    
    ll total = 0;
    while(!pq.empty()) {
        edge cur = pq.top();
        pq.pop();
        if(find(cur.u) != find(cur.v)) {
            unite(cur.u, cur.v);
            total += cur.w;
        }
    }
    cout << total << "\n";

    for (int i = 1; i <= q; ++i) {
        // Reset parent array for each event
        for(int j = 1; j <= n; j++) {
            par[j] = j;
        }
        // Re-calculate the minimum spanning tree after each event
        pq.push({e[i].first, e[i].second, e[i].second});
        ll ans = 0;
        while(!pq.empty()) {
            edge cur = pq.top();
            pq.pop();
            if(find(cur.u) != find(cur.v)) {
                unite(cur.u, cur.v);
                ans += cur.w;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
