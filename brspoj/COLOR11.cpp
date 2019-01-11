#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  int start_x, start_y;
  cin >> start_x >> start_y;
  start_x--, start_y--;

  int k;
  cin >> k;

  vector<vector<bool>> grid(n, vector<bool>(m, true));
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    grid[x][y] = false;
  }

  queue<pair<int, int>> q;
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  vis[start_x][start_y] = true;
  q.emplace(start_x, start_y);

  while (!q.empty()) {
    int x, y;
    tie(x, y) = q.front();
    q.pop();

    for (int dx = -1; dx < 2; dx++)
      for (int dy = -1; dy < 2; dy++) {
        const int new_x = x + dx;
        const int new_y = y + dy;
        if (0 <= new_x && new_x < n && 0 <= new_y && new_y < m &&
            !vis[new_x][new_y] && grid[new_x][new_y]) {
          q.emplace(new_x, new_y);
          vis[new_x][new_y] = true;
        }
      }
  }

  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) ans += vis[i][j];

  cout << ans << endl;
}
