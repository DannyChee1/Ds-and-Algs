#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 3;

int a[MAXN];
ll bit[MAXN], freq[MAXN];

void update(ll bit[], int pos, int val) {
  for(int i = pos; i < MAXN; i += i & -i) bit[i] += val;
}

ll query(ll bit[], int pos) {
  ll ret = 0;
  for(int i = pos; i > 0; i -= i & -i) ret += bit[i];
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    update(bit, i, a[i]);
    update(freq, a[i], 1);
  }
  for(int i = 1; i <= m; ++i) {
    int x, y;
    char op;
    cin >> op;
    if(op == 'C') {
      cin >> x >> y;
      update(bit, x, -a[x]+y);
      update(freq, a[x], -1);
      update(freq, y, 1);
      a[x] = y;
    }
    else if(op == 'S') {
      cin >> x >> y;
      cout << query(bit, y) - query(bit, x - 1) << '\n';
    }
    else {
      cin >> x;
      cout << query(freq, x) << '\n';
    }
  }
}