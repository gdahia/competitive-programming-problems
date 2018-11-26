#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<unsigned long long> seq(n);
  for (unsigned long long& i : seq) cin >> i;

  vector<vector<int>> adj(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (2 * seq[i] == seq[j] || (seq[i] % 3 == 0 && seq[i] / 3 == seq[j]))
        adj[i].push_back(j);

  for (int i = 0; i < n; i++) {
    queue<int> q;
    vector<int> vis(n, false);
    vis[i] = true;
    q.push(i);
    vector<int> ans;
    while (!q.empty()) {
      const int curr = q.front();
      q.pop();
      ans.push_back(curr);

      for (const int target : adj[curr])
        if (!vis[target]) {
          vis[target] = true;
          q.push(target);
        }
    }

    if (ans.size() == n) {
      for (const int j : ans) cout << seq[j] << " ";
      cout << endl;
    }
  }
}
