#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> int3;

void solve(const int n, const int m) {
  vector<int3> edges;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.emplace_back(u, v, w);
  }

  vector<int> dist(n, 0x3f3f3f3f);
  dist[0] = 0;

  for (int i = 0; i < n - 1; i++)
    for (const int3& e : edges) {
      int u, v, w;
      tie(u, v, w) = e;
      dist[v] = min(dist[v], w + dist[u]);
    }

  for (const int3& e : edges) {
    int u, v, w;
    tie(u, v, w) = e;
    if (w + dist[u] < dist[v]) {
      cout << "possible" << endl;
      return;
    }
  }

  cout << "not possible" << endl;
}

int main() {
  int c;
  cin >> c;
  while (c--) {
    int n, m;
    cin >> n >> m;
    solve(n, m);
  }
}
