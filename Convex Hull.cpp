#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<int, 3> E;
const int MM = 2003;
int K, N, M, st, ed, dis[MM][202]; vector<E> adj[MM];
int main(){
    cin >> K >> N >> M;
    for(int i=1, u, v, t, h; i<=M; i++){
        cin >> u >> v >> t >> h;
        adj[u].push_back({v, t, h}); adj[v].push_back({u, t, h});
    }
    cin >> st >> ed;
    priority_queue<E, vector<E>, greater<E>> q;
    memset(dis, 0x3f, sizeof(dis));
    dis[st][0] = 0;   q.push({0, st, 0}); //{dis, vertex, hull_usage}
    while(!q.empty()) {
       auto [d, u, h] = q.top(); q.pop();
       if(d > dis[u][h]) continue;
       if(u == ed) { cout << dis[u][h] << endl;   return 0;}
       for(auto [v, t, h2] : adj[u]){
            int nh= h + h2;
            if(nh < K && dis[v][nh] > dis[u][h] + t) {
                dis[v][nh] = dis[u][h] + t;   q.push({dis[v][nh], v, nh});
            }
       }
    }
    cout << -1 << endl;
}