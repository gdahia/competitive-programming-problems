#include <bits/stdc++.h>
using namespace std;

void solve(const int a, const vector<double>& fats) {
  const double loga = log(a);
  int l = 1;
  int r = fats.size() - 1;
  while (l < r) {
    const int m = l + (r - l + 1) / 2;
    if (fats[m] <= m * loga)
      l = m;
    else
      r = m - 1;
  }

  cout << l + 1 << endl;
}

int main() {
  vector<double> fats(10000001);
  fats[1] = 0;
  for (int i = 2; i <= 10000000; i++) fats[i] = fats[i - 1] + log(i);

  int t;
  cin >> t;
  while (t--) {
    int a;
    cin >> a;
    solve(a, fats);
  }
}
