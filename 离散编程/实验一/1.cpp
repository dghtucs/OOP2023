#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjMatrix(n + 1, vector<int>(n + 1, 0));
    vector<vector<pair<int, int>>> adjList(n + 1);
    vector<pair<int, pair<int, int>>> edges(m + 1);

    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        edges[i] = {v, {w, adjList[u].empty() ? 0 : adjList[u].back().second}};
        adjList[u].push_back({v, i});

        if(adjMatrix[u][v] == 0) {
            adjMatrix[u][v] = w;
        } else {
            adjMatrix[u][v] = -1;
        }
    }

    // 输出邻接矩阵
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }

    // 输出邻接表
    for(int i = 1; i <= n; ++i) {
        if(adjList[i].empty()) {
            cout << "0\n";
        } else {
            cout << adjList[i].back().second << "\n";
        }
    }
    for(int i = 1; i <= m; ++i) {
        cout << edges[i].first << " " << edges[i].second.first << " " << edges[i].second.second << "\n";
    }

    return 0;
}
