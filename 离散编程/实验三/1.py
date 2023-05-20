import heapq

def read_input():
    n = int(input().strip())
    points = []
    for _ in range(n):
        x, y = map(int, input().split())
        points.append((x, y))
    return n, points

def cost(p1, p2):
    return abs(p1[0]-p2[0])**3 + abs(p1[1]-p2[1])**3

def minimum_cost(n, points):
    visited = [False]*n
    min_heap = [(0, 0)]  # cost from node 0
    total_cost = 0

    while min_heap:
        c, v = heapq.heappop(min_heap)
        if not visited[v]:
            visited[v] = True
            total_cost += c
            for i in range(n):
                if not visited[i]:
                    heapq.heappush(min_heap, (cost(points[v], points[i]), i))
    return total_cost

def main():
    n, points = read_input()
    print(minimum_cost(n, points))

if __name__ == "__main__":
    main()
