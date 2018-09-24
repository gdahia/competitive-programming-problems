#include <iostream>

using namespace std;

void solve(const int t, const int n, const int k) {
  unsigned int dp[n][k + 1][2];
  dp[0][0][0] = 1;
  dp[0][0][1] = 1;

  for (int i = 1; i <= k; i++) dp[0][i][0] = dp[0][i][1] = 0;

  for (int i = 1; i < n; i++) {
    dp[i][0][0] = dp[i - 1][0][0] + dp[i - 1][0][1];
    dp[i][0][1] = dp[i - 1][0][0];
  }

  for (int i = 1; i < n; i++)
    for (int j = 1; j <= k; j++) {
      dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
      dp[i][j][1] = dp[i - 1][j][0] + dp[i - 1][j - 1][1];
    }

  cout << t << " " << dp[n - 1][k][0] + dp[n - 1][k][1] << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int i, n, k;
    cin >> i >> n >> k;
    solve(i, n, k);
  }
}
