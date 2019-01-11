#include <bits/stdc++.h>
using namespace std;

void solve(const int n, const int q) {
  vector<int> seq(q);
  for (int& i : seq) cin >> i;

  int ans = 0;
  for (int i = 0; i < q; i++) {
    int l = i;
    int r = q - 1;
    while (l < r) {
      const int m = l + (r - l + 1) / 2;
      if (seq[m] < seq[i] + n)
        l = m;
      else
        r = m - 1;
    }
    ans = max(ans, l - i);
  }

  cout << n - ans - 1 << endl;
}

int main() {
  int n, q;
  while (cin >> n >> q, n | q) solve(n, q);
}
