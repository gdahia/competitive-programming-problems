#include <bits/stdc++.h>
using namespace std;

struct cmp {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
    return a > b;
  }
};

void solve(const int n, const int m) {
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[--u].emplace_back(--v, w);
  }

  int s, t;
  cin >> s >> t;
  s--;
  t--;

  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
  vector<int> dist(n, 0x3f3f3f3f);
  dist[s] = 0;
  pq.emplace(0, s);
  while (!pq.empty()) {
    int v, d;
    tie(d, v) = pq.top();
    pq.pop();

    if (dist[v] == d) {
      for (const pair<int, int>& e : adj[v]) {
        int u;
        tie(u, d) = e;
        if (dist[u] > dist[v] + d) {
          dist[u] = dist[v] + d;
          pq.emplace(dist[u], u);
        }
      }
    }
  }

  if (dist[t] == 0x3f3f3f3f)
    cout << -1 << endl;
  else
    cout << dist[t] << endl;
}

int main() {
  int n, m;
  while (cin >> n >> m, n | m) solve(n, m);
}
