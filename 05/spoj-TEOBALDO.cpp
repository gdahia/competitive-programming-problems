#include <bits/stdc++.h>
using namespace std;

void solve(const int n, const int m) {
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int source, target, max_dist;
  cin >> source >> target >> max_dist;
  source--;
  target--;

  queue<pair<int, int>> q;
  vector<vector<bool>> vis(n, vector<bool>(max_dist + 1, false));
  vis[source][0] = true;
  q.emplace(source, 0);
  while (!q.empty()) {
    int current, dist;
    tie(current, dist) = q.front();
    q.pop();

    if (dist < max_dist)
      for (const int next : adj[current])
        if (!vis[next][dist + 1]) {
          vis[next][dist + 1] = true;
          q.emplace(next, dist + 1);
        }
  }

  if (vis[target][max_dist])
    cout << "Yes, Teobaldo can travel." << endl;
  else
    cout << "No, Teobaldo can not travel." << endl;
}

int main() {
  int n, m;
  while (cin >> n >> m, n | m) solve(n, m);
}
