#include <bits/stdc++.h>
using namespace std;

void solve(const int n, const int t) {
  map<string, int> indices;
  for (int i = 0; i < n; i++) {
    string city;
    cin >> city;
    indices[city] = i;
  }

  int m;
  cin >> m;

  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < m; i++) {
    string s1, s2;
    int w;
    cin >> s1 >> s2 >> w;
    const int u = indices[s1];
    const int v = indices[s2];
    edges.emplace_back(u, v, w);
  }

  vector<vector<int>> dists(max(m, n), vector<int>(n, 0x3f3f3f3f));
  dists[0][0] = 0;
  for (int i = 1; i < n; i++)
    for (int j = 0; j < m; j++) {
      int u, v, w;
      tie(u, v, w) = edges[j];
      dists[i][v] = min({dists[i - 1][u] + w, dists[i][v], dists[i - 1][v]});
    }

  if (t > 1) cout << endl;
  cout << "Scenario #" << t << endl;
  int q;
  cin >> q;
  while (q--) {
    int qry;
    cin >> qry;
    qry = min(qry + 1, max(m, n) - 1);
    if (dists[qry][n - 1] == 0x3f3f3f3f)
      cout << "No satisfactory flights" << endl;
    else
      cout << "Total cost of flight(s) is $" << dists[qry][n - 1] << endl;
  }
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n;
    cin >> n;
    solve(n, i);
  }
}
