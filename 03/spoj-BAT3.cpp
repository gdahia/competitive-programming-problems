#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve(const int n, const int m) {
  vector<int> seq(n);
  for (int i = 0; i < n; i++) cin >> seq[i];

  vector<int> lis;
  for (int i = 0; i < n; i++) {
    int is = 1;
    for (int j = 0; j < i; j++)
      if (seq[i] < seq[j] || j == m) is = max(is, lis[j] + 1);
    lis.push_back(is);
  }

  int ans = 0;
  for (const int is : lis) ans = max(ans, is);

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    solve(n, m);
  }
}
