#include <bits/stdc++.h>
using namespace std;

void dfs(const int source, const vector<vector<int>>& adj, vector<bool>& vis) {
  vis[source] = true;
  for (const int target : adj[source])
    if (!vis[target]) dfs(target, adj, vis);
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

  vector<bool> vis(n, false);
  dfs(0, adj, vis);

  bool ans = true;
  for (int i = 0; i < n; i++) ans &= vis[i];

  cout << "Teste " << t << endl;
  cout << (ans ? "normal" : "falha") << endl;
  cout << endl;
}

int main() {
  int n, m, t = 1;
  while (cin >> n >> m, n | m) solve(n, m, t++);
}
