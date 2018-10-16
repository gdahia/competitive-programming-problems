#include <bits/stdc++.h>
using namespace std;

void dfs(const int source, const int color, const vector<vector<int>>& adj,
         int& time, vector<int>& parent, vector<int>& colors, vector<int>& pre,
         vector<int>& low) {
  low[source] = pre[source] = time++;
  colors[source] = color;
  for (const int target : adj[source])
    if (!colors[target]) {
      parent[target] = source;
      dfs(target, color, adj, time, parent, colors, pre, low);
      low[source] = min(low[source], low[target]);
    } else if (parent[source] != target)
      low[source] = min(low[source], pre[target]);

  time++;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  map<pair<int, int>, bool> spc;
  for (int i = 0; i < m; i++) {
    int u, v, x;
    cin >> u >> v >> x;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    spc[{u, v}] = x;
    spc[{v, u}] = x;
  }

  int fst, lst;
  cin >> fst >> lst;
  fst--, lst--;

  vector<int> parent(n, -1);
  vector<int> colors(n, 0);
  vector<int> low(n, 0);
  vector<int> pre(n, 0);
  int time = 1;
  dfs(fst, 1, adj, time, parent, colors, pre, low);

  vector<vector<int>> non_bridges(n);
  for (int source = 0; source < n; source++)
    for (const int target : adj[source])
      if (parent[target] == source && low[target] <= pre[source]) {
        non_bridges[target].push_back(source);
        non_bridges[source].push_back(target);
      }

  parent.assign(n, -1);
  colors.assign(n, 0);
  low.assign(n, 0);
  pre.assign(n, 0);
  int blocks = 0;
  for (int source = 0; source < n; source++)
    if (!pre[source]) {
      time = 1;
      blocks++;
      dfs(source, source + 1, non_bridges, time, parent, colors, pre, low);
    }

  vector<vector<int>> block_adj(n);
  map<pair<int, int>, bool> block_adj_spc;
  vector<bool> block_spc(n, false);
  for (int source = 0; source < n; source++)
    for (const int target : adj[source])
      if (colors[target] != colors[source]) {
        block_adj[colors[target] - 1].push_back(colors[source] - 1);
        block_adj[colors[source] - 1].push_back(colors[target] - 1);
        const bool is_spc = spc[{target, source}];
        block_adj_spc[{colors[source] - 1, colors[target] - 1}] |= is_spc;
        block_adj_spc[{colors[target] - 1, colors[source] - 1}] |= is_spc;
      } else if (spc[{target, source}])
        block_spc[colors[source] - 1] = true;

  vector<int> block_parent(n, -1);
  vector<int> block_vis(n, 0);
  vector<int> block_pre(n, 0);
  vector<int> block_low(n, 0);
  time = 1;
  dfs(colors[fst] - 1, 1, block_adj, time, block_parent, block_vis, block_pre,
      block_low);

  bool possible = false;
  int cur = colors[lst] - 1;
  while (cur >= 0) {
    if (block_spc[cur] || block_adj_spc[{cur, block_parent[cur]}]) {
      possible = true;
      break;
    }
    cur = block_parent[cur];
  }

  cout << (possible ? "YES" : "NO") << endl;
}
