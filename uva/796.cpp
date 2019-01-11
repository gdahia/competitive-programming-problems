#include <bits/stdc++.h>
using namespace std;

void dfs(const int source, const int parent, const vector<vector<int>>& adj,
         int& time, vector<int>& pre, vector<int>& low) {
  pre[source] = low[source] = time++;
  for (const int target : adj[source])
    if (!pre[target]) {
      dfs(target, source, adj, time, pre, low);
      low[source] = min(low[source], low[target]);
    } else if (target != parent)
      low[source] = min(low[source], pre[target]);
  time++;
}

void solve(const int n) {
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n; i++) {
    int v, m;
    char dummy;
    cin >> v >> dummy >> m >> dummy;
    for (int j = 0; j < m; j++) {
      int u;
      cin >> u;
      adj[v].push_back(u);
    }
  }

  vector<int> pre(n + 1, 0);
  vector<int> low(n + 1, 0);
  int time = 1;
  for (int i = 0; i < n; i++)
    if (!pre[i]) dfs(i, -1, adj, time, pre, low);

  vector<pair<int, int>> ans;
  for (int i = 0; i < n; i++)
    for (const int target : adj[i])
      if (pre[i] < low[target])
        ans.emplace_back(min(i, target), max(i, target));

  sort(ans.begin(), ans.end());

  cout << ans.size() << " critical links" << endl;
  for (const pair<int, int>& p : ans)
    cout << p.first << " - " << p.second << endl;
  cout << endl;
}

int main() {
  int n;
  while (cin >> n) solve(n);
}
