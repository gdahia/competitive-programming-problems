#include <bits/stdc++.h>
using namespace std;

double solve(const int a, const int b, const int c) {
  double l = 0;
  double r = c;
  while (r - l >= 1e-9) {
    const double m = (r + l) / 2;
    if (a * m + b * sin(m) < c)
      l = m;
    else
      r = m;
  }

  return l;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << fixed << setprecision(6) << solve(a, b, c) << endl;
  }
}
