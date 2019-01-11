#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> int2;

struct cmp {
  bool operator()(const int2& a, const int2& b) { return a > b; }
};

void dijkstra(const int source, const vector<vector<int2>>& adj,
              vector<int>& dist, vector<vector<int2>>& parent) {
  dist.assign(adj.size(), 0x3f3f3f3f);
  dist[source] = 0;
  priority_queue<int2, vector<int2>, cmp> pq;
  pq.emplace(0, source);

  while (!pq.empty()) {
    int u, d;
    tie(d, u) = pq.top();
    pq.pop();

    if (d == dist[u])
      for (const int2& e : adj[u])
        if (e.second + d == dist[e.first])
          parent[e.first].emplace_back(u, 1);
        else if (e.second + d < dist[e.first]) {
          parent[e.first].clear();
          parent[e.first].emplace_back(u, 1);

          dist[e.first] = e.second + d;
          pq.emplace(e.second + d, e.first);
        }
  }
}

void solve(const int n, const int m) {
  int source, target;
  cin >> source >> target;

  vector<vector<int2>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
  }

  vector<int> dists;
  vector<vector<int2>> min_paths(n);
  dijkstra(source, adj, dists, min_paths);

  if (dists[target] == 0x3f3f3f3f) {
    cout << -1 << endl;
    return;
  }

  vector<vector<int2>> forbidden_edges(n);
  dijkstra(target, min_paths, dists, forbidden_edges);

  vector<vector<int2>> new_adj(n);
  for (int i = 0; i < n; i++)
    for (const int2& e : adj[i]) {
      bool ok = true;
      for (const int2& fe : forbidden_edges[i])
        if (fe.first == e.first) {
          ok = false;
          break;
        }
      if (ok) new_adj[i].push_back(e);
    }

  min_paths.assign(n, vector<int2>());
  dijkstra(source, new_adj, dists, min_paths);

  if (dists[target] == 0x3f3f3f3f)
    cout << -1 << endl;
  else
    cout << dists[target] << endl;
}

int main() {
  int n, m;
  while (cin >> n >> m, n | m) solve(n, m);
}
