#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solve(const int n) {
  vector<int> seq(n);
  for (int& i : seq) cin >> i;

  map<int, int> prev;
  for (int i = 0; i < n; i++) prev[seq[i]] = prev[seq[i] - 1] + 1;
  int ans = 0;
  for (const auto p : prev) ans = max(p.second, ans);
  cout << n - ans << endl;
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
