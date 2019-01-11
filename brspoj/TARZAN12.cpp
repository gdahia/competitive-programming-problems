#include <bits/stdc++.h>
using namespace std;

int sqr(const int a) { return a * a; }

void dfs(const int source, const vector<vector<int>>& adj, vector<bool>& vis) {
  vis[source] = true;
  for (const int target : adj[source])
    if (!vis[target]) dfs(target, adj, vis);
}

int main() {
  int n, d;
  cin >> n >> d;

  vector<int> x(n);
  vector<int> y(n);
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

  vector<vector<int>> adj(n);
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (sqr(x[i] - x[j]) + sqr(y[i] - y[j]) <= sqr(d)) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }

  vector<bool> vis(n, false);
  dfs(0, adj, vis);

  bool ans = true;
  for (const bool vis_ : vis)
    if (!vis_) {
      ans = false;
      break;
    }

  cout << (ans ? "S" : "N") << endl;
}
