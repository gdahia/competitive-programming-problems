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
  if (rank[target_root] > rank[source_root])
    dsu[source_root] = target_root;
  else {
    dsu[target_root] = source_root;
    if (rank[target_root] == rank[source_root]) rank[source_root]++;
  }
}

void solve(const int n, const int m, const int t) {
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.emplace_back(w, --u, --v);
  }

  vector<int> dsu(n);
  vector<int> rank(n);
  for (int i = 0; i < n; i++) {
    dsu[i] = i;
    rank[i] = 0;
  }

  sort(edges.begin(), edges.end());
  long long ans = 0;
  for (const tuple<int, int, int>& edge : edges) {
    int u, v, w;
    tie(w, u, v) = edge;

    const int u_root = find(u, dsu);
    const int v_root = find(v, dsu);
    if (u_root != v_root) {
      merge(u_root, v_root, dsu, rank);
      ans += w;
    }
  }

  cout << "Instancia " << t << endl;
  cout << ans << endl << endl;
}

int main() {
  int n, m, t = 1;
  while (cin >> n >> m) solve(n, m, t++);
}
