#include <bits/stdc++.h>
using namespace std;

int find(const int source, vector<int>& dsu) {
  if (source == dsu[source]) return source;
  const int root = find(dsu[source], dsu);
  dsu[source] = root;
  return root;
}

int merge(const int source, const int target, vector<int>& dsu,
          vector<int>& sz) {
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

void solve(const int n, const int m, const int t) {
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
  vector<pair<int, int>> ans;
  for (const tuple<int, int, int>& edge : edges) {
    int u, v, w;
    tie(w, u, v) = edge;

    const int u_root = find(u, dsu);
    const int v_root = find(v, dsu);
    if (u_root != v_root) {
      merge(u_root, v_root, dsu, sz);
      ans.emplace_back(u + 1, v + 1);
    }
  }

  cout << "Teste " << t << endl;
  for (const pair<int, int>& edge : ans)
    cout << min(edge.first, edge.second) << " " << max(edge.first, edge.second)
         << endl;
  cout << endl;
}

int main() {
  int n, m, t = 1;
  while (cin >> n >> m, n | m) solve(n, m, t++);
}
