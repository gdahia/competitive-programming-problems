#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> int3;
typedef tuple<int, int, int, int> int4;

struct cmp {
  bool operator()(const int4& a, const int4& b) { return a > b; }
};

int main() {
  int n, m;
  char c;
  cin >> n >> m >> c;

  int s, t;
  cin >> s >> t;
  s--;
  t--;

  vector<vector<int3>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v, w1, w2;
    cin >> u >> v >> w1 >> w2;
    u--;
    v--;
    adj[u].emplace_back(v, w1, w2);
  }

  priority_queue<int4, vector<int4>, cmp> pq;
  pq.emplace(0, 0, 0, s);

  vector<int3> dists(n, int3(0x3f3f3f3f, 0x3f3f3f3f, 0x3f3f3f3f));
  dists[s] = int3(0, 0, 0);

  while (!pq.empty()) {
    int u, d1, d2, d3;
    tie(d1, d2, d3, u) = pq.top();
    pq.pop();

    if (dists[u] == int3(d1, d2, d3))
      for (const int3& e : adj[u]) {
        int v, w1, w2;
        if (c == 'P')
          tie(v, w1, w2) = e;
        else
          tie(v, w2, w1) = e;

        const int3 duv = int3(d1 + w1, d2 + w2, d3 + 1);
        if (duv < dists[v]) {
          dists[v] = duv;
          pq.emplace(d1 + w1, d2 + w2, d3 + 1, v);
        }
      }
  }

  int dt1, dt2, dt3;
  tie(dt1, dt2, dt3) = dists[t];
  if (dt1 == 0x3f3f3f3f)
    cout << -1 << endl;
  else if (c == 'P')
    cout << dt1 << " " << dt2 << " " << dt3 - 1 << endl;
  else
    cout << dt2 << " " << dt1 << " " << dt3 - 1 << endl;
}
