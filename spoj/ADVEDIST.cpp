#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void solve(const string& a, const string& b) {
  const int n = a.size();
  const int m = b.size();

  int da[26];
  for (int i = 0; i < 26; i++) da[i] = 0;

  int dp[n + 1][m + 1];
  for (int i = 0; i <= n; i++) dp[i][0] = i;
  for (int j = 0; j <= m; j++) dp[0][j] = j;
  for (int i = 1; i <= n; i++) {
    int db = 0;
    for (int j = 1; j <= m; j++) {
      const int k = da[b[j - 1] - 'a'];
      const int l = db;

      int cost;
      if (a[i - 1] != b[j - 1])
        cost = 1;
      else {
        cost = 0;
        db = j;
      }

      dp[i][j] =
          min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost});

      if (k > 0 && l > 0)
        dp[i][j] =
            min(dp[i][j], dp[k - 1][l - 1] + (i - k - 1) + (j - l - 1) + 1);
    }
    da[a[i - 1] - 'a'] = i;
  }

  cout << dp[n][m] << endl;
}

int main() {
  string a, b;
  while (cin >> a >> b, a != "*" || b != "*") solve(a, b);
}
