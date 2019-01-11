#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void solve(const string& s) {
  const int n = s.size();

  int dp[n + 1][n + 1];
  for (int i = 0; i <= n; i++) dp[i][0] = dp[0][i] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (s[i - 1] == s[n - j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

  cout << n - dp[n][n] << endl;
}

int main() {
  int n;
  string s;
  cin >> n >> s;
  solve(s);
}
