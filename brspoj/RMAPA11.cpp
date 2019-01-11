#include <bits/stdc++.h>
using namespace std;

int find(const int source, vector<int>& dsu) {
  if (source == dsu[source]) return source;
  const int root = find(dsu[source], dsu);
  dsu[source] = root;
  return root;
}

int merge(const int source, const int target, vector<int>& sz,
          vector<int>& dsu) {
  const int source_root = find(source, dsu);
  const int target_root = find(target, dsu);
  if (sz[source_root] < sz[target_root]) {
    sz[target_root] += sz[source_root];
    dsu[source_root] = dsu[target_root];
  } else {
    sz[source_root] += sz[target_root];
    dsu[target_root] = dsu[source_root];
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.emplace_back(w, --u, --v);
  }

  vector<int> dsu(n);
  vector<int> sz(n);
  for (int i = 0; i < n; i++) {
    dsu[i] = i;
    sz[i] = 1;
  }

  sort(edges.begin(), edges.end());
  int ans = 0;
  for (const tuple<int, int, int>& edge : edges) {
    int u, v, w;
    tie(w, u, v) = edge;

    const int u_root = find(u, dsu);
    const int v_root = find(v, dsu);
    if (u_root != v_root) {
      merge(u_root, v_root, sz, dsu);
      ans += w;
    }
  }

  cout << ans << endl;
}
