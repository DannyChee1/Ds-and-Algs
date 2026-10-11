#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> comp;
    DSU(int x) : comp(x + 1, -1) {}
    void unite(int a, int b) {
        a = repr(a), b = repr(b);
        if (a == b) return;
        if (-comp[a] < -comp[b]) swap(a, b);
        comp[a] += comp[b];
        comp[b] = a;
    }
    int repr(int x) { return comp[x] < 0 ? x : comp[x] = repr(comp[x]); }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	DSU dsu(n);
	while (q-- > 0) {
		int t, u, v;
		cin >> t >> u >> v;
		if (t == 1)
			cout << (dsu.repr(u) == dsu.repr(v)) << '\n';
		else dsu.merge(u, v);
	}
}
