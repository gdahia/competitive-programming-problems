#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> grid(n, vector<int>(m));
  int start_x, start_y;
  vector<pair<int, int>> end;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 3) {
        start_x = i;
        start_y = j;
      } else if (grid[i][j] == 0)
        end.emplace_back(i, j);
    }

  queue<pair<int, int>> q;
  q.emplace(start_x, start_y);
  vector<vector<int>> vis(n, vector<int>(m, -1));
  vis[start_x][start_y] = 0;

  const int dx[] = {0, 0, 1, -1};
  const int dy[] = {1, -1, 0, 0};
  while (!q.empty()) {
    int i, j;
    tie(i, j) = q.front();
    q.pop();

    for (int k = 0; k < 4; k++) {
      const int x = i + dx[k];
      const int y = j + dy[k];
      if (0 <= x && x < n && 0 <= y && y < m && vis[x][y] < 0 &&
          grid[x][y] != 2) {
        vis[x][y] = vis[i][j] + 1;
        q.emplace(x, y);
      }
    }
  }

  int ans = m * n;
  for (pair<int, int> pos : end)
    if (vis[pos.first][pos.second] > 0)
      ans = min(ans, vis[pos.first][pos.second]);
  cout << ans << endl;
}
