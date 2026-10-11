#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define c(...) GET_MACRO(__VA_ARGS__, c4, c3, c2, c1)(__VA_ARGS__)
#define c1(x) cerr << #x <<": \n"; _print(x); cerr << endl;
#define c3(x, start, n) cerr << #x <<": \n"; _print(x, start, n); cerr << endl;
#define c4(x, start, n, m) cerr << #x <<": \n"; _print(x, start, n, m); cerr << endl;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }

template <class T> void _print(vector <T>& v) { cerr << "[ "; for(T i : v) { _print(i); cerr << " "; } cerr << "]\n"; }
template <class T> void _print(vector<vector <T>>& v) { for(auto i : v) { cerr << "[ "; for(T j : i) { _print(j); cerr << " "; }	cerr << "]\n"; } }
template <int row> void _print(int(&a)[row], int start, int n)
{
    cerr << "[ "; for(int i = start; i < n; ++i) cerr << a[i] << " "; cerr << "]\n";
}
template <int rows, int cols> void _print(int(&a)[rows][cols], int start, int n, int m)
{
    for(int i = start; i < n; ++i) { cerr << "[ "; for(int j = 0; j < m; ++j) cerr << a[i][j] << " "; cerr << "]\n"; }
}

const int MM = 200005;
ll a[MM], segtree[4 * MM];

void build(int v, int l, int r) {
    if(l == r)
        segtree[v] = a[l];
    else {
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        segtree[v] = segtree[2 * v] + segtree[2 * v + 1];
    }
}

void update(int v, int l, int r, int pos, ll val) {
    if(l == r)
        segtree[v] = val;
    else {
        int mid = (l + r) / 2;
        if(pos <= mid)
            update(2 * v, l, mid, pos, val);
        else update(2 * v + 1, mid + 1, r, pos, val);
        segtree[v] = segtree[2 * v] + segtree[2 * v + 1];
    }
}

ll query(int v, int l, int r, int L, int R) {
    if(L > R) return 0;
    if (l == L && r == R) return segtree[v];
    int m = (l + r) / 2;
    return query(2 * v, l, m, L, min(R, m)) +  query(2 * v + 1, m + 1, r, max(L, m + 1), R);
}

ll query2(int v, int l, int r, int L, int R) {
  if(l == L && r == R) return segtree[v];
  int m = (l + r) / 2;
  if(R <= m) return query2(2 * v, l, m, L, R);
  else if(L > m) return query2(2*v+1, m+1, r, L, R);
  else return min(query2(2*v, l, m, L, m), query2(2*v+1, m+1, r, m+1, R));
}

int main() {
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    while(q-- > 0) {
        char c;
        ll a, b;
        cin >> c >> a >> b;
        if(c == 'S') cout << query(1, 1, n, a, b) << endl;
        else update(1, 1, n, a, b);
    }

}