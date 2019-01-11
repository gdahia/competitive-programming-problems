#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;

  vector<long long> seq(n);
  for (long long& i : seq) {
    cin >> i;
    i *= i;
  }

  long long ans = 0;
  while (m--) {
    long long x, y;
    cin >> x >> y;

    const long long rad = x * x + y * y;
    auto lb = lower_bound(seq.begin(), seq.end(), rad);

    ans += n - (lb - seq.begin());
  }

  cout << ans << endl;
}
