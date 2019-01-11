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
    int v, d;
    tie(d, v) = pq.top();
    pq.pop();

    if (d == dist[v])
      for (const pair<int, int>& e : adj[v]) {
        int u, w;
        tie(w, u) = e;
        if (dist[u] > d + w) {
          dist[u] = d + w;
          pq.emplace(d + w, u);
        }
      }
  }

  return dist;
}

void solve(const int n, const int m) {
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    adj[u].emplace_back(w, v);
  }

  vector<vector<int>> dists(n);
  for (int i = 0; i < n; i++) dists[i] = dijkstra(i, adj);

  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (dists[i][j] != 0x3f3f3f3f && dists[j][i] != 0x3f3f3f3f) {
        adj[i].emplace_back(0, j);
        adj[j].emplace_back(0, i);
      }

  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    auto dist = dijkstra(s, adj);
    if (dist[t] == 0x3f3f3f3f)
      cout << "Nao e possivel entregar a carta" << endl;
    else
      cout << dist[t] << endl;
  }
  cout << endl;
}

int main() {
  int n, m;
  while (cin >> n >> m, n | m) solve(n, m);
}
