#include <iostream>
#include <vector>
#include <algorithm>
#include<fstream>


using namespace std;

const int MAXN = 15;
vector<int> graph[MAXN + 5];
int color[MAXN + 5];
bool check[MAXN + 5][MAXN + 5];  // check whether two variables conflict
int N, M, maxcolor;

void dfs(int x, int curcolor) {
    if(curcolor >= maxcolor) return;  // pruning, if current color number is larger, then return
    if(x > N) {
        maxcolor = curcolor - 1;  // update the maximum color number
        return;
    }
    for(int i = 1; i <= curcolor; ++i) {  // traverse color
        bool flag = true;
        for(int j = 0; j < graph[x].size(); ++j) {
            if(color[graph[x][j]] == i) {  // if there is a conflict, then this color cannot be used
                flag = false;
                break;
            }
        }
        if(flag) {  // if this color can be used
            color[x] = i;
            dfs(x + 1, curcolor);
            
        }
    }
    color[x] = curcolor + 1;  // assign a new color
    dfs(x + 1, curcolor + 1);
    
}

int main() {
    ifstream cin("in.txt");
    cin >> N >> M;
    int u, v;
    for(int i = 1; i <= M; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        check[u][v] = check[v][u] = true;
    }
    maxcolor = N;  // initialize the max color number to N
    dfs(1, 0);
    cout << maxcolor << endl;
    for(int i = 1; i <= N; ++i) {
        cout << color[i] << ' ';
    }
    return 0;
}
