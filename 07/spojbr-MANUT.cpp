#include <bits/stdc++.h>
using namespace std;

int dfs(const int source, const vector<vector<int>>& adj, int& time,
        vector<int>& parent, vector<int>& pre, vector<int>& low) {
  pre[source] = low[source] = time++;
  int subtree_sz = 0;
  for (const int target : adj[source])
    if (!pre[target]) {
      parent[target] = source;
      dfs(target, adj, time, parent, pre, low);
      low[source] = min(low[source], low[target]);
      subtree_sz++;
    } else if (target != parent[source])
      low[source] = min(low[source], pre[target]);
  time++;

  return subtree_sz;
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

  vector<int> ans;
  vector<int> pre(n, 0);
  vector<int> low(n, 0);
  vector<int> parent(n, -1);
  int time = 1;
  if (dfs(0, adj, time, parent, pre, low) > 1) ans.push_back(1);

  for (int i = 1; i < n; i++) {
    bool is_articulation = false;
    for (const int target : adj[i])
      if (parent[target] == i && low[target] >= pre[i]) {
        is_articulation = true;
        break;
      }
    if (is_articulation) ans.push_back(i + 1);
  }

  cout << "Teste " << t << endl;
  if (ans.empty()) cout << "nenhum";
  for (const int i : ans) cout << i << " ";
  cout << endl << endl;
}

int main() {
  int n, m, t = 1;
  while (cin >> n >> m, n | m) solve(n, m, t++);
}
