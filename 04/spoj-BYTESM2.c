#include <stdio.h>

int max(const int a, const int b, const int c) {
  if (a > b && a > c) return a;
  if (b > c) return b;
  return c;
}

void solve(const int n, const int m) {
  int grid[n + 1][m + 1];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &grid[i][j]);

  int dp[n + 1][m + 2];
  for (int i = 0; i < n; i++) dp[i][0] = dp[i][m + 1] = 0;
  for (int j = 0; j <= m + 1; j++) dp[0][j] = 0;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      dp[i][j] =
          grid[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]);

  int ans = 0;
  for (int j = 1; j <= m; j++)
    if (dp[n][j] > ans) ans = dp[n][j];

  printf("%d\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    solve(n, m);
  }
}
