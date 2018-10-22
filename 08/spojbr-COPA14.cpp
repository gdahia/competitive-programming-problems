#include <bits/stdc++.h>
using namespace std;

struct edge_t {
  int w, u, v;
  edge_t(int w, int u, int v) : w(w), u(u), v(v) {}
};

bool cmp(const edge_t& a, const edge_t& b) { return a.w < b.w; }

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

int main() {
  int n, m[2];
  cin >> n >> m[0] >> m[1];

  vector<edge_t> edges[2];
  for (int j = 0; j < 2; j++)
    for (int i = 0; i < m[j]; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      edges[j].push_back(edge_t(w, --u, --v));
    }

  int ans = 0;
  vector<int> dsu(n);
  vector<int> rank(n);
  for (int i = 0; i < n; i++) {
    dsu[i] = i;
    rank[i] = 0;
  }
  for (int j = 0; j < 2; j++) {
    sort(edges[j].begin(), edges[j].end(), cmp);
    for (int i = 0; i < m[j]; i++) {
      const edge_t& edge = edges[j][i];
      const int u = edge.u;
      const int v = edge.v;
      const int w = edge.w;

      const int u_root = find(u, dsu);
      const int v_root = find(v, dsu);
      if (u_root != v_root) {
        merge(u_root, v_root, dsu, rank);
        ans += w;
      }
    }
  }

  cout << ans << endl;
}
