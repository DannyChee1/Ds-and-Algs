from collections import deque

adj = []

def topo_sort():
    n = len(adj)
    indegree = [0] * n

    for i in range(n):
        for neighbour in adj[i]:
            indegree[neighbour] += 1

    q = deque(node for node in range(n) if indegree[node] == 0)
    order = []

    while len(q):
        node = q.popleft()
        order.append(node)
        for neighbour in adj[node]:
            indegree[neighbour] -= 1
            if indegree[neighbour] == 0:
                q.append(neighbour)

    if len(order) == n:
        return order
    return None