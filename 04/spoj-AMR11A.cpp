#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve(const int n, const int m) {
  vector<vector<int>> grid(n, vector<int>(m));
  for (vector<int>& row : grid)
    for (int& cell : row) cin >> cell;

  vector<vector<int>> dp(n, vector<int>(m));
  dp[n - 1][m - 1] = grid[n - 1][m - 1];
  for (int i = n - 2; i >= 0; i--)
    dp[i][m - 1] = grid[i][m - 1] + min(0, dp[i + 1][m - 1]);
  for (int j = m - 2; j >= 0; j--)
    dp[n - 1][j] = grid[n - 1][j] + min(0, dp[n - 1][j + 1]);
  for (int i = n - 2; i >= 0; i--)
    for (int j = m - 2; j >= 0; j--)
      dp[i][j] = grid[i][j] + min(0, max(dp[i + 1][j], dp[i][j + 1]));

  // for (int i = 0; i < n; i++) {
  // for (int j = 0; j < m; j++) cout << dp[i][j] << " ";
  // cout << endl;
  //}
  cout << 1 - dp[0][0] << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    solve(n, m);
  }
}
