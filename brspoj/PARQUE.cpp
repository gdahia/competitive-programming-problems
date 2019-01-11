#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(const string& a, const string& b, const int ndt) {
  const int n = a.size();
  const int m = b.size();

  int dp[n + 1][m + 1];
  for (int i = 0; i <= n; i++) dp[i][0] = 0;
  for (int j = 0; j <= m; j++) dp[0][j] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i - 1] == b[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

  vector<char> ans(m + n - dp[n][m]);
  int i = n;
  int j = m;
  int k = ans.size() - 1;
  while (i != 0 || j != 0) {
    if (i == 0) {
      j--;
      ans[k--] = b[j];
    } else if (j == 0) {
      i--;
      ans[k--] = a[i];
    } else if (a[i - 1] == b[j - 1]) {
      i--;
      j--;
      ans[k--] = a[i];
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      i--;
      ans[k--] = a[i];
    } else {
      j--;
      ans[k--] = b[j];
    }
  }

  cout << "Teste " << ndt << endl;
  cout << string(ans.begin(), ans.end()) << endl;
  cout << endl;
}

int main() {
  int ndt = 1;
  string a, b;
  while (cin >> a, a != "#") {
    cin >> b;
    solve(a, b, ndt++);
  }
}
