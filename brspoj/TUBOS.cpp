#include <bits/stdc++.h>
using namespace std;

int dfs(const int source, const vector<vector<int>>& adj, int& time,
        vector<int>& parent, vector<int>& pre, vector<int>& low) {
  low[source] = pre[source] = time++;
  int subtree_sz = 0;
  for (const int target : adj[source])
    if (!pre[target]) {
      subtree_sz++;
      parent[target] = source;
      dfs(target, adj, time, parent, pre, low);
      low[source] = min(low[source], low[target]);
    } else if (parent[source] != target)
      low[source] = min(low[source], pre[target]);
  time++;

  return subtree_sz;
}

void solve(const int n, const int m) {
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  bool ans = true;
  vector<int> parent(n, -1);
  vector<int> pre(n, 0);
  vector<int> low(n, 0);
  int time = 1;
  dfs(0, adj, time, parent, pre, low);

  for (int i = 0; i < n; i++) {
    for (const int target : adj[i])
      if (low[target] > pre[i]) {
        ans = false;
        break;
      }
  }

  cout << (ans ? "S" : "N") << endl;
}

int main() {
  int n, m;
  while (cin >> n >> m, n | m) solve(n, m);
}
