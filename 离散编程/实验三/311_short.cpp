#include<bits/stdc++.h>
using namespace std;

struct Edge {
    short u, v;
    long long w;
};

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

short find(short x, vector<short>& parent) {
    if(parent[x] != x) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

void union_nodes(short x, short y, vector<short>& parent, vector<short>& rank) {
    short px = find(x, parent);
    short py = find(y, parent);
    
    if(rank[px] > rank[py]) {
        parent[py] = px;
    } else if(rank[py] > rank[px]) {
        parent[px] = py;
    } else {
        parent[py] = px;
        rank[px]++;
    }
}

short main() {
    short n;
    cin >> n;
    vector<pair<short, short>> poshorts(n);
    for(short i = 0; i < n; i++) {
        cin >> poshorts[i].first >> poshorts[i].second;
    }
    
    vector<Edge> edges;
    for(short i = 0; i < n; i++) {
        for(short j = i+1; j < n; j++) {
            long long cost = pow(abs(poshorts[i].first - poshorts[j].first), 3) + pow(abs(poshorts[i].second - poshorts[j].second), 3);
            edges.push_back({i, j, cost});
        }
    }
    
    sort(edges.begin(), edges.end(), compare);
    
    vector<short> parent(n), rank(n, 0);
    for(short i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    long long total_cost = 0;
    for(auto e : edges) {
        if(find(e.u, parent) != find(e.v, parent)) {
            total_cost += e.w;
            union_nodes(e.u, e.v, parent, rank);
        }
    }
    
    cout << total_cost << endl;

    return 0;
}
