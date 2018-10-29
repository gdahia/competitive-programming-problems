#include <bits/stdc++.h>
using namespace std;

struct cmp {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
    return a > b;
  }
};

vector<int> dijkstra(const int source,
                     const vector<vector<pair<int, int>>>& adj) {
  vector<int> dist(adj.size(), 0x3f3f3f3f);
  dist[source] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
  pq.emplace(0, source);

  while (!pq.empty()) {
    int s, d;
    tie(d, s) = pq.top();
    pq.pop();

    if (dist[s] == d)
      for (const pair<int, int>& e : adj[s]) {
        int u, w;
        tie(w, u) = e;
        if (d + w < dist[u]) {
          dist[u] = d + w;
          pq.emplace(d + w, u);
        }
      }
  }

  return dist;
}

void solve(const int n, const int m, const int c, const int k) {
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    if (u >= c || v == u + 1) adj[u].emplace_back(w, v);
    if (v >= c || u == v + 1) adj[v].emplace_back(w, u);
  }

  auto dists = dijkstra(k, adj);

  cout << dists[c - 1] << endl;
}

int main() {
  int n, m, c, k;
  while (cin >> n >> m >> c >> k, n | m | c | k) solve(n, m, c, k);
}
