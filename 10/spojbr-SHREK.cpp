#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  double s_x, s_y;
  cin >> s_x >> s_y;

  vector<double> c_xs(n), c_ys(n);
  for (int i = 0; i < n; i++) cin >> c_xs[i] >> c_ys[i];

  double s_v, c_v;
  cin >> s_v >> c_v;

  if (c_xs[0] == s_x && c_ys[0] == s_y) {
    cout << "0.00" << endl;
    return 0;
  }

  double c_tdist = 0;
  for (int i = 0; i < n - 1; i++) {
    const double sb_dist = hypot(s_x - c_xs[i + 1], s_y - c_ys[i + 1]);
    const double ab_dist = hypot(c_xs[i] - c_xs[i + 1], c_ys[i] - c_ys[i + 1]);
    if (sb_dist / s_v <= (c_tdist + ab_dist) / c_v) {
      double l = 0;
      double r = 1;
      while (r - l >= 1e-12) {
        const double m = (l + r) / 2;
        const double i_x = m * c_xs[i] + (1 - m) * c_xs[i + 1];
        const double i_y = m * c_ys[i] + (1 - m) * c_ys[i + 1];
        const double si_dist = hypot(s_x - i_x, s_y - i_y);
        const double ai_dist = hypot(c_xs[i] - i_x, c_ys[i] - i_y);
        if (si_dist / s_v > (c_tdist + ai_dist) / c_v)
          r = m;
        else
          l = m;
      }
      const double i_x = l * c_xs[i] + (1 - l) * c_xs[i + 1];
      const double i_y = l * c_ys[i] + (1 - l) * c_ys[i + 1];
      const double si_dist = hypot(s_x - i_x, s_y - i_y);
      const double ai_dist = hypot(c_xs[i] - i_x, c_ys[i] - i_y);
      cout << fixed << setprecision(2) << si_dist / s_v << endl;
      return 0;
    }

    c_tdist += ab_dist;
  }

  cout << "impossivel" << endl;
}
