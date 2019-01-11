#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

void solve(const int n) {
  const ull ttn = (1 << n);

  vector<int> grid(n, 0);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      int cell;
      cin >> cell;
      grid[i] |= (cell << j);
    }

  vector<vector<ull>> dp(n, vector<ull>(ttn, 0));
  for (int j = 1; j < ttn; j++)
    if (grid[0] & j) dp[0][j] = 1;

  for (int i = 1; i < n; i++)
    for (int k = 1; k < ttn; k <<= 1)
      if (grid[i] & k)
        for (int j = 1; j < ttn; j++)
          if (k & j) dp[i][j] += dp[i - 1][j & ~k];

  cout << dp[n - 1][ttn - 1] << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    solve(n);
  }
}
