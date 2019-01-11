#include <bits/stdc++.h>
using namespace std;

int main() {
  map<string, int> indices;
  int name_i = 1;
  string name;
  set<int> adj[10000];
  vector<int> in_deg(10000, -1);
  while (cin >> name) {
    if (!indices[name]) indices[name] = name_i++;
    const int idx = indices[name];
    set<int> rev_adj;
    while (cin >> name, name != "0") {
      if (!indices[name]) indices[name] = name_i++;
      adj[indices[name]].insert(idx);
      rev_adj.insert(indices[name]);
    }
    in_deg[idx] = rev_adj.size();
  }

  queue<int> q;
  int ans = 0;
  for (const pair<string, int>& index : indices)
    if (!in_deg[index.second]) {
      q.push(index.second);
      ans++;
    }

  while (!q.empty()) {
    const int source = q.front();
    q.pop();

    for (const int target : adj[source])
      if (in_deg[target]) {
        in_deg[target]--;
        if (!in_deg[target]) {
          q.push(target);
          ans++;
        }
      }
  }

  cout << ans << endl;
}
