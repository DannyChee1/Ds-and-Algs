#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MM = 2e5+3, base1 = 131, base2 = 10007, mod = 1e9+7;
string N, H;  ll hsh1[MM], pw1[MM], hsh2[MM], pw2[MM];  set<pl> st;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> H;
    int n = N.size(), m = H.size();
    vector<int> fn(26, 0), fh(26, 0);
    for(char c : N) fn[c-'a']++;
    hsh1[0] = hsh2[0] = 0;  pw1[0] = pw2[0] = 1;
    for(int i=1; i<=m; i++){
        hsh1[i] = (hsh1[i-1] * base1 + H[i-1])%mod;
        hsh2[i] = (hsh2[i-1] * base2 + H[i-1])%mod;
        pw1[i] = pw1[i-1] * base1 % mod;
        pw2[i] = pw2[i-1] * base2 % mod;
    }
    for(int i=0; i<m; i++){
        fh[H[i]-'a']++;
        if(i >= n) fh[H[i-n]-'a']--;
        if(fn == fh){ // a permutation
            int l = i - n + 2, r = i+1;
            ll sub1 = (hsh1[r] - hsh1[l-1] * pw1[r-l+1] % mod + mod) % mod;
            ll sub2 = (hsh2[r] - hsh2[l-1] * pw2[r-l+1] % mod + mod) % mod;
            st.insert({sub1, sub2});
            //cout << H.substr(i-n+1, n) << " " << sub1 << " " << sub2 << endl;
        }
    }
    cout << st.size() << endl;
}