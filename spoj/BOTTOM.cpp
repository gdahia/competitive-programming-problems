#include <bits/stdc++.h>
using namespace std;

bool dfs(const int source, const int color, const vector<vector<int>>& adj,
         vector<int>& colors, stack<int>& post) {
  colors[source] = color;
  bool is_bottom = true;
  for (const int target : adj[source]) {
    if (!colors[target])
      is_bottom &= dfs(target, color, adj, colors, post);
    else if (colors[source] != colors[target])
      is_bottom = false;
  }
  post.push(source);
  return is_bottom;
}

void solve(const int n, const int m) {
  vector<vector<int>> adj(n);
  vector<vector<int>> rev_adj(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
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

  set<int> non_bottom_colors;
  for (int i = 0; i < n; i++)
    for (const int target : adj[i])
      if (colors[i] != colors[target]) {
        non_bottom_colors.insert(colors[i]);
        break;
      }

  vector<int> ans;
  for (int i = 0; i < n; i++)
    if (!non_bottom_colors.count(colors[i])) ans.push_back(i);

  sort(ans.begin(), ans.end());

  for (const int v : ans) cout << v + 1 << " ";
  cout << endl;
}

int main() {
  int n;
  while (cin >> n, n) {
    int m;
    cin >> m;
    solve(n, m);
  }
}
