#include <bits/stdc++.h>
using namespace std;

void dfs(const int source, const int color, const vector<vector<int>>& adj,
         vector<int>& colors, stack<int>& post) {
  colors[source] = color;
  for (const int target : adj[source])
    if (!colors[target]) dfs(target, color, adj, colors, post);
  post.push(source);
}

void solve(const int n, const int t) {
  map<string, int> indices;
  vector<vector<int>> adj(4000);
  vector<vector<int>> rev_adj(4000);
  vector<string> names;
  for (int i = 0; i < n; i++) {
    string name;
    int idx[2];
    for (int j = 0; j < 2; j++) {
      cin >> name;
      names.push_back(name);

      string pos_name = (name[0] == '!' ? name.substr(1) : name);

      if (!indices.count(pos_name)) indices[pos_name] = 4 * i + 2 * j;

      if (!indices.count("!" + pos_name))
        indices["!" + pos_name] = 4 * i + 1 + 2 * j;

      idx[j] = indices[name];
    }

    adj[idx[0] ^ 1].push_back(idx[1]);
    adj[idx[1] ^ 1].push_back(idx[0]);

    rev_adj[idx[0]].push_back(idx[1] ^ 1);
    rev_adj[idx[1]].push_back(idx[0] ^ 1);
  }

  vector<int> vis(4000, 0);
  stack<int> post;
  for (int i = 0; i < 4000; i++)
    if (!vis[i]) dfs(i, 1, adj, vis, post);

  vector<int> colors(4000, 0);
  stack<int> tmp;
  while (!post.empty()) {
    const int source = post.top();
    post.pop();

    if (!colors[source]) dfs(source, source + 1, rev_adj, colors, tmp);
  }

  bool ans = true;
  for (const string& name : names) {
    const int i = indices[name];
    if (colors[i] == colors[i ^ 1]) {
      ans = false;
      break;
    }
  }

  cout << "Instancia " << t << endl;
  cout << (ans ? "sim" : "nao") << endl;
  cout << endl;
}

int main() {
  int n, t = 1;
  while (cin >> n) solve(n, t++);
}
