#include <bits/stdc++.h>
using namespace std;

int find(const int source, vector<int>& dsu) {
  if (source == dsu[source]) return source;
  const int root = find(dsu[source], dsu);
  dsu[source] = root;
  return root;
}

int merge(const int source, const int target, vector<int>& dsu,
          vector<int>& rank) {
  const int source_root = find(source, dsu);
  const int target_root = find(target, dsu);

  if (rank[source_root] > rank[target_root])
    dsu[target_root] = source_root;
  else {
    dsu[source_root] = target_root;
    if (rank[source_root] == rank[target_root]) rank[target_root]++;
  }
}

void solve(const int n) {
  vector<pair<double, double>> vertices;
  vector<tuple<double, int, int>> edges;
  for (int i = 0; i < n; i++) {
    double x, y;
    cin >> x >> y;
    for (int j = 0; j < i; j++) {
      const pair<double, double>& v = vertices[j];
      edges.emplace_back(hypot(v.first - x, v.second - y), i, j);
    }
    vertices.emplace_back(x, y);
  }

  vector<int> dsu(n);
  vector<int> rank(n);
  for (int i = 0; i < n; i++) {
    dsu[i] = i;
    rank[i] = 0;
  }

  double ans = 0;
  sort(edges.begin(), edges.end());
  for (const tuple<double, int, int>& edge : edges) {
    int u, v;
    double w;
    tie(w, u, v) = edge;

    const int u_root = find(u, dsu);
    const int v_root = find(v, dsu);
    if (u_root != v_root) {
      merge(u_root, v_root, dsu, rank);
      ans = w;
    }
  }

  cout << fixed << setprecision(4) << ans << endl;
}

int main() {
  int n;
  while (cin >> n, n) solve(n);
}
