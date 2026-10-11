class DSU:
    def __init__(self, n):
        self.comps = [-1] * n

    def find(self, x):
        comps = self.comps
        while comps[x] >= 0:
            if comps[comps[x]] >= 0:
                comps[x] = comps[comps[x]]
            x = comps[x]
        return x
    
    def union(self, a, b):
        a, b = self.find(a), self.find(b)
        if a == b:
            return False
        if self.comps[a] > self.comps[b]:
            a, b = b, a
        self.comps[a] += self.comps[b]
        self.comps[b] = a
        return True