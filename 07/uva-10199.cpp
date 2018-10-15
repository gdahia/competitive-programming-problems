#include <bits/stdc++.h>
using namespace std;

int dfs(const int source, const vector<vector<int>>& adj, int& time,
        vector<int>& parent, vector<int>& pre, vector<int>& low) {
  low[source] = pre[source] = time++;
  int subtree_sz = 0;
  for (const int target : adj[source])
    if (!pre[target]) {
      subtree_sz++;
      parent[target] = source;
      dfs(target, adj, time, parent, pre, low);
      low[source] = min(low[source], low[target]);
    } else if (parent[source] != target)
      low[source] = min(low[source], pre[target]);
  time++;
  return subtree_sz;
}

void solve(const int n, const int t) {
  map<string, int> indices;
  vector<string> names(n);
  for (int i = 0; i < n; i++) {
    cin >> names[i];
    indices[names[i]] = i;
  }

  int m;
  cin >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    string s, r;
    cin >> s >> r;
    const int u = indices[s];
    const int v = indices[r];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<string> ans;
  vector<int> pre(n, 0);
  vector<int> low(n, 0);
  vector<int> parent(n, -1);
  for (int i = 0; i < n; i++)
    if (!pre[i]) {
      int time = 1;
      if (dfs(i, adj, time, parent, pre, low) > 1) ans.push_back(names[i]);
    }

  for (int i = 0; i < n; i++)
    if (pre[i] > 1) {
      bool is_articulation = false;
      for (const int target : adj[i])
        if (parent[target] == i && low[target] >= pre[i]) {
          is_articulation = true;
          break;
        }
      if (is_articulation) ans.push_back(names[i]);
    }

  sort(ans.begin(), ans.end());

  if (t > 1) cout << endl;
  cout << "City map #" << t << ": " << ans.size() << " camera(s) found" << endl;
  for (const string s : ans) cout << s << endl;
}

int main() {
  int n, t = 1;
  while (cin >> n, n) solve(n, t++);
}
