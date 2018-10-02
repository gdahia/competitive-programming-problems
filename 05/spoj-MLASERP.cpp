#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> m >> n;

  int start_i, start_j;
  int end_i, end_j;
  vector<vector<bool>> grid(n, vector<bool>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      if (c == '*')
        grid[i][j] = false;
      else {
        grid[i][j] = true;
        if (c == 'C') {
          end_i = start_i;
          end_j = start_j;
          start_i = i;
          start_j = j;
        }
      }
    }

  vector<vector<int>> dist(n, vector<int>(m, -1));
  queue<pair<int, int>> q;
  q.emplace(start_i, start_j);
  while (!q.empty()) {
    int i, j;
    tie(i, j) = q.front();
    q.pop();

    for (int di = i + 1; di < n; di++)
      if (!grid[di][j])
        break;
      else if (dist[di][j] < 0) {
        dist[di][j] = dist[i][j] + 1;
        q.emplace(di, j);
      }

    for (int di = i - 1; di >= 0; di--)
      if (!grid[di][j])
        break;
      else if (dist[di][j] < 0) {
        dist[di][j] = dist[i][j] + 1;
        q.emplace(di, j);
      }

    for (int dj = j + 1; dj < m; dj++)
      if (!grid[i][dj])
        break;
      else if (dist[i][dj] < 0) {
        dist[i][dj] = dist[i][j] + 1;
        q.emplace(i, dj);
      }

    for (int dj = j - 1; dj >= 0; dj--)
      if (!grid[i][dj])
        break;
      else if (dist[i][dj] < 0) {
        dist[i][dj] = dist[i][j] + 1;
        q.emplace(i, dj);
      }
  }

  cout << dist[end_i][end_j] << endl;
}
