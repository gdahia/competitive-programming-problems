#include <bits/stdc++.h>
using namespace std;

void dfs(const int source, const int color, const vector<vector<int>>& adj,
         vector<int>& colors, stack<int>& post) {
  colors[source] = color;
  for (const int target : adj[source])
    if (!colors[target]) dfs(target, color, adj, colors, post);
  post.push(source);
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  vector<vector<int>> rev_adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    rev_adj[v].push_back(u);
  }

  vector<int> vis(n, 0);
  stack<int> post;
  for (int i = 0; i < n; i++)
    if (!vis[i]) dfs(i, 1, adj, vis, post);

  vector<int> colors(n, 0);
  stack<int> tmp;
  while (!post.empty()) {
    const int source = post.top();
    post.pop();

    if (!colors[source]) dfs(source, source + 1, rev_adj, colors, tmp);
  }

  vector<int> ans(n, n + 2);
  for (int i = 0; i < n; i++) ans[colors[i] - 1] = min(ans[colors[i] - 1], i);

  for (int i = 0; i < n; i++) cout << ans[colors[i] - 1] << endl;
}
