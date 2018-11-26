#include <bits/stdc++.h>
using namespace std;

bool dfs(const int source, vector<bool>& vis, const vector<vector<int>>& adj) {
  vis[source] = true;
  bool is_cycle = adj[source].size() == 2;
  for (const int target : adj[source])
    if (!vis[target]) is_cycle &= dfs(target, vis, adj);

  return is_cycle;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int ans = 0;
  vector<bool> vis(n, false);
  for (int source = 0; source < n; source++)
    if (!vis[source])
      if (dfs(source, vis, adj)) ans++;

  cout << ans << endl;
}
