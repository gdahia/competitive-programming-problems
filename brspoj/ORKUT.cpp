#include <bits/stdc++.h>
using namespace std;

void solve(const int n, const int t) {
  map<string, int> indices;
  vector<string> names;
  for (int i = 0; i < n; i++) {
    string name;
    cin >> name;
    indices[name] = i;
    names.push_back(name);
  }

  vector<vector<int>> adj(n);
  vector<int> in_deg(n, 0);
  for (int i = 0; i < n; i++) {
    string name;
    int k;
    cin >> name >> k;
    const int idx = indices[name];
    in_deg[idx] = k;
    for (int j = 0; j < k; j++) {
      cin >> name;
      adj[indices[name]].push_back(idx);
    }
  }

  queue<int> q;
  vector<string> ans;
  for (int i = 0; i < n; i++)
    if (!in_deg[i]) {
      q.push(i);
      ans.push_back(names[i]);
    }

  while (!q.empty()) {
    const int source = q.front();
    q.pop();

    for (const int target : adj[source])
      if (in_deg[target]) {
        in_deg[target]--;
        if (!in_deg[target]) {
          q.push(target);
          ans.push_back(names[target]);
        }
      }
  }

  cout << "Teste " << t << endl;
  if (ans.size() == n) {
    for (const string& name : ans) cout << name << " ";
    cout << endl << endl;
  } else
    cout << "impossivel" << endl << endl;
}

int main() {
  int n, m, t = 1;
  while (cin >> n, n) solve(n, t++);
}
