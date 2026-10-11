import heapq

INF = 10**9
adj = []

def dijkstra(source, dists, parent):
    n = len(adj)
    dists[:] = [INF] * n 
    parent[:] = [-1] * n

    dists[source] = 0
    pq = [(0, source)]

    while len(pq):
        distance, node = heapq.heappop(pq)
        if distance > dists[node]:
            continue

        for neighbour, length in adj[node]:
            total = distance + length
            if total < dists[neighbour]:
                dists[neighbour] = total
                parent[neighbour] = node
                heapq.heappush(pq, (total, neighbour))

