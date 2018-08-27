#include <iostream>
#include <vector>
using namespace std;

void solve(const int n, const int k) {
  vector<int> prices(k + 1);
  for (int i = 1; i <= k; i++) cin >> prices[i];

  vector<bool> mask(k + 1, false);
  vector<int> ans(k + 1);
  vector<int> amount(k + 1);
  mask[0] = true;
  ans[0] = 0;
  amount[0] = 0;
  for (int i = 1; i <= k; i++)
    if (prices[i] >= 0)
      for (int j = 0; j <= k - i; j++)
        if (mask[j] && amount[j] < n)
          if (!mask[j + i] || ans[j] + prices[i] < ans[j + i]) {
            mask[j + i] = true;
            ans[j + i] = ans[j] + prices[i];
            amount[j + i] = amount[j] + 1;
          }

  if (mask[k])
    cout << ans[k] << endl;
  else
    cout << -1 << endl;
}

int main() {
  int c;
  cin >> c;
  while (c--) {
    int n, k;
    cin >> n >> k;
    solve(n, k);
  }
}
