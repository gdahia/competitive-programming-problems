#include <bits/stdc++.h>
using namespace std;

bool dfs(const int source, const vector<vector<int>>& adj, vector<int>& vis,
         const int color) {
  vis[source] = color;
  for (const int target : adj[source])
    if (vis[source] == vis[target] ||
        (!vis[target] && !dfs(target, adj, vis, -color)))
      return false;

  return true;
}

void solve(const int n, const int m, const int t) {
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
  vector<int> vis(n, 0);
  for (int i = 0; i < n; i++)
    if (!vis[i] && !dfs(i, adj, vis, 1)) {
      ans = false;
      break;
    }

  cout << "Instancia " << t << endl;
  cout << (ans ? "sim" : "nao") << endl;
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, t = 1;
  while (cin >> n >> m) solve(n, m, t++);
}
