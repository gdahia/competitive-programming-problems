#include <bits/stdc++.h>
using namespace std;

void dfs(const int source, const int parent, const vector<vector<int>>& adj,
         int& time, vector<int>& pre, vector<int>& low) {
  low[source] = pre[source] = time++;
  for (const int target : adj[source]) {
    if (!pre[target]) {
      dfs(target, source, adj, time, pre, low);
      low[source] = min(low[source], low[target]);
    } else if (target != parent)
      low[source] = min(low[source], pre[target]);
  }
  time++;
}

void solve(const int n, const int m) {
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> pre(n, 0);
  vector<int> low(n, 0);
  int time = 1;
  for (int i = 0; i < n; i++)
    if (!pre[i]) dfs(i, -1, adj, time, pre, low);

  vector<pair<int, int>> ans;
  for (int i = 0; i < n; i++)
    for (const int target : adj[i])
      if (low[target] > pre[i])
        ans.emplace_back(min(i, target), max(i, target));

  sort(ans.begin(), ans.end());

  cout << ans.size();
  for (const pair<int, int>& p : ans) cout << " " << p.first << " " << p.second;
  cout << endl;
}

int main() {
  int n, m;
  while (cin >> n >> m, n | m) solve(n, m);
}
