#include <bits/stdc++.h>
using namespace std;

int find(const int source, vector<int>& dsu) {
  if (source == dsu[source]) return source;
  const int root = find(dsu[source], dsu);
  dsu[source] = root;
  return root;
}

bool merge(const int source, const int target, vector<int>& dsu,
           vector<int>& rank) {
  const int source_root = find(source, dsu);
  const int target_root = find(target, dsu);

  if (source_root == target_root) return false;

  if (rank[target_root] > rank[source_root])
    dsu[source_root] = target_root;
  else {
    dsu[target_root] = source_root;
    if (rank[target_root] == rank[source_root]) rank[source_root]++;
  }

  return true;
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
  vector<int> mst;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    tie(w, u, v) = edges[i];

    if (merge(u, v, dsu, rank)) mst.push_back(i);
  }

  int ans = 0x3f3f3f3f;
  const int len = mst.size();
  bool has_second = false;
  for (int j = 0; j < len; j++) {
    int st = 0;
    int tree_sz = 0;
    for (int i = 0; i < n; i++) {
      dsu[i] = i;
      rank[i] = 0;
    }

    for (int i = 0; i < m; i++) {
      int u, v, w;
      tie(w, u, v) = edges[i];

      if (i != mst[j] && merge(u, v, dsu, rank)) {
        st += w;
        tree_sz++;
      }
    }

    if (tree_sz == n - 1) {
      ans = min(ans, st);
      has_second = true;
    }
  }

  cout << "Case #" << t << " : ";
  if (len != n - 1)
    cout << "No way";
  else if (!has_second)
    cout << "No second way";
  else
    cout << ans;
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n, m;
    cin >> n >> m;
    solve(n, m, i);
  }
}
