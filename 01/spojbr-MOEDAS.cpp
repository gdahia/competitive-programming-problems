#include <iostream>
#include <vector>
using namespace std;

void solve(const int m, const int n) {
  vector<int> coins(n);
  for (int i = 0; i < n; i++) cin >> coins[i];

  vector<bool> mask(m + 1, false);
  vector<int> ans(m + 1);
  mask[0] = true;
  ans[0] = 0;
  for (int i = 1; i <= m; i++)
    for (const int coin : coins)
      if (i - coin >= 0 && mask[i - coin])
        if (!mask[i] || ans[i] > ans[i - coin] + 1) {
          mask[i] = true;
          ans[i] = ans[i - coin] + 1;
        }

  if (mask[m])
    cout << ans[m] << endl;
  else
    cout << "Impossivel" << endl;
}

int main() {
  int n, m;
  while (cin >> m, m != 0) {
    cin >> n;
    solve(m, n);
  }
}
