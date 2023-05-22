#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    long long w;
};

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

int find(int x, vector<int>& parent) {
    if(parent[x] != x) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

void union_nodes(int x, int y, vector<int>& parent, vector<int>& rank) {
    int px = find(x, parent);
    int py = find(y, parent);
    
    if(rank[px] > rank[py]) {
        parent[py] = px;
    } else if(rank[py] > rank[px]) {
        parent[px] = py;
    } else {
        parent[py] = px;
        rank[px]++;
    }
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    vector<Edge> edges;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            long long cost = pow(abs(points[i].first - points[j].first), 3) + pow(abs(points[i].second - points[j].second), 3);
            edges.push_back({i, j, cost});
        }
    }
    
    sort(edges.begin(), edges.end(), compare);
    
    vector<int> parent(n), rank(n, 0);
    for(int i = 0; i < n; i++) {
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
