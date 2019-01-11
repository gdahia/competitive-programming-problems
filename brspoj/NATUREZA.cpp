#include <bits/stdc++.h>
using namespace std;

int dfs(const int source, const vector<vector<int>>& adj, vector<bool>& vis) {
  vis[source] = true;
  int subtree = 1;
  for (const int target : adj[source])
    if (!vis[target]) subtree += dfs(target, adj, vis);
  return subtree;
}

void solve(const int n, const int m) {
  map<string, int> idx;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    idx[s] = i;
  }

  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    string r, s;
    cin >> r >> s;
    adj[idx[r]].push_back(idx[s]);
    adj[idx[s]].push_back(idx[r]);
  }

  int ans = 1;
  vector<bool> vis(n, false);
  for (int i = 0; i < n; i++)
    if (!vis[i]) ans = max(ans, dfs(i, adj, vis));

  cout << ans << endl;
}

int main() {
  int n, m;
  while (cin >> n >> m, n | m) solve(n, m);
}
