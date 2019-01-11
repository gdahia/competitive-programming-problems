#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(const int t, const string& s) {
  const int n = s.size();
  vector<int> suffix(n + 1);
  suffix[n] = 0;
  suffix[n - 1] = s[n - 1] - '0';
  for (int i = n - 2; i >= 0; i--) suffix[i] = suffix[i + 1] + s[i] - '0';

  vector<vector<int>> dp(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    dp[0][i] = 1;
    for (int j = 1; j <= i; j++) {
      dp[j][i] = 0;
      for (int k = 0; k < j; k++) {
        if (suffix[k] - suffix[j] <= suffix[j] - suffix[i + 1])
          dp[j][i] += dp[k][j - 1];
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) ans += dp[i][n - 1];

  cout << t << ". " << ans << endl;
}

int main() {
  int t = 1;
  string s;
  while (cin >> s, s != "bye") solve(t++, s);
}
