#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void solve(const string& a, const string& b) {
  const int n = a.size();
  const int m = b.size();

  int dp[n + 1][m + 1];
  for (int i = 0; i <= n; i++) dp[i][0] = i;
  for (int j = 1; j <= m; j++) dp[0][j] = 2 * j;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i - 1] == b[j - 1])
        // dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
        dp[i][j] = dp[i - 1][j - 1];
      else
        dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 2);

  cout << dp[n][m] * 15 << endl;
}

int main() {
  string a, b;
  while (cin >> a, a != "#") {
    cin >> b;
    solve(a, b);
  }
}
