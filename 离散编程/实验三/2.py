import sys
from operator import itemgetter

def kruskal(nodes, edges):
    forest = [-1] * nodes
    mst = []
    edges = sorted(edges, key=itemgetter(2))

    for e in edges:
        n1, n2, _ = e
        t1 = find(n1, forest)
        t2 = find(n2, forest)

        if t1 != t2:
            mst.append(e)
            forest[t2] = t1

    return mst

def find(node, forest):
    if forest[node] == -1:
        return node
    else:
        return find(forest[node], forest)

def calculate_cost(edges):
    return sum(e[2] for e in edges)

n = int(sys.stdin.readline())
points = []
for _ in range(n):
    x, y = map(int, sys.stdin.readline().split())
    points.append((x, y))

edges = []
for i in range(n):
    for j in range(i+1, n):
        cost = abs(points[i][0] - points[j][0])**3 + abs(points[i][1] - points[j][1])**3
        edges.append((i, j, cost))

mst = kruskal(n, edges)
total_cost = calculate_cost(mst)
print(total_cost)
