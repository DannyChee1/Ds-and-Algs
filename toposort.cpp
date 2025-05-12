int n; // number of vertices
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
}


#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_N = 100000;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> graph[MAX_N];
  int indegree[MAX_N]{};
  queue<int> q;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a - 1].push_back(b - 1);
    indegree[b - 1]++;
  }
  for (int i = 0; i < n; i++) {
    // locate the nodes with indegree 0 and push them into the queue
    if (indegree[i] == 0) { q.push(i); }
  }
  vector<int> order;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    // add the current node to the order
    order.push_back(curr);
    for (int next : graph[curr]) {
      // remove the current node from the graph
      indegree[next]--;
      // push any new nodes with indegree 0 into the queue
      if (indegree[next] == 0) { q.push(next); }
    }
  }
  // if there isn't a valid topological sorting
  if (order.size() != n) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  cout << order[0] + 1;
  for (int i = 1; i < n; i++) { cout << " " << order[i] + 1; }
  cout << endl;
  return 0;
}
