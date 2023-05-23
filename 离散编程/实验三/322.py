from itertools import combinations

def solve():
    # 读入N和M
    N, M = map(int, input().split())
    
    # 初始化邻接矩阵
    graph = [[1]*N for _ in range(N)]
    for i in range(N):
        graph[i][i] = 0
    
    # 根据输入的约束关系，更新邻接矩阵
    for _ in range(M):
        a, b = map(int, input().split())
        a -= 1  # 转换为0-based索引
        b -= 1  # 转换为0-based索引
        graph[a][b] = graph[b][a] = 0
    
    # 寻找最大团
    max_clique = 1
    register = [0] * N
    for k in range(1, N+1):
        for subset in combinations(range(N), k):
            if all(graph[u][v] for u in subset for v in subset):
                if k > max_clique:
                    max_clique = k
                    for i in subset:
                        register[i] = max_clique
    
    print(max_clique)
    print(' '.join(map(str, register)))

solve()
