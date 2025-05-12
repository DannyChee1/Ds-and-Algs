#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 1e6+2;
int N, Q;  ll val[4*MM], lz[4*MM];
void build(int l, int r, int rt){
    if(l == r) { cin >> val[rt]; lz[rt] = 0; return; }
    int m = (l + r)/2;
    build(l, m, 2*rt); build(m+1, r, 2*rt+1);
    val[rt] = min(val[2*rt], val[2*rt+1]);
}
void push_down(int rt){
    val[2*rt] = max(0LL, val[2*rt] - lz[rt]);  lz[2*rt] += lz[rt];
    val[2*rt+1] = max(0LL, val[2*rt+1] - lz[rt]);  lz[2*rt+1] += lz[rt];
    lz[rt] = 0;
}
void update(int l, int r, int x, int y, int z, int rt){
    if(l == x && y == r) { val[rt] = max(0LL, val[rt] - z); lz[rt] += z; return; }
    if(lz[rt]) push_down(rt);
    int m = (l + r)/2;
    if(y <= m) update(l, m, x, y, z, 2*rt);
    else if(x > m) update(m+1, r, x, y, z, 2*rt+1);
    else { update(l, m, x, m, z, 2*rt);  update(m+1, r, m+1, y, z, 2*rt+1); }
    val[rt] = min(val[2*rt], val[2*rt+1]);
}
ll query(int l, int r, int x, int y, int rt){
    if(l == x && y == r) return val[rt];
    if(lz[rt]) push_down(rt);
    int m = (l + r)/2;
    if(y <= m) return query(l, m, x, y, 2*rt);
    if(x > m) return query(m+1, r, x, y, 2*rt + 1);
    return min(query(l, m, x, m, 2*rt), query(m+1, r, m+1, y, 2*rt+1));
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q; build(1, N, 1);
    for(int i=1, x, y, z; i<=Q; i++) {
        cin >> x >> y >> z;
        update(1, N, x, y, z, 1);
        cout << query(1, N, x, y, 1) << " " << val[1] << "\n";
    }
}