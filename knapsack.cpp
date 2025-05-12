#include <bits/stdc++.h>
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;


int main() {
  fast_cin();
  int n, x;
  cin >> n >> x;
  vector<long long> coins(n), dp(x+1, 0);
  for (long long& c : coins) {
    cin >> c;
    if(c <= x) dp[c] = 1;
  }
  for (int i = 0; i <= x; ++i) {
    if (i != 0) {
      for (long long& c : coins) {
        if (i + c <= x)
        {
          dp[i + c] += dp[i];
          dp[i + c] %= 1000000007;
        }

      }
    }
  }
  cout << dp[x];

