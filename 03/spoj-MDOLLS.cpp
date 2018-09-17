#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
  return a.first < b.first || (a.first == b.first && a.second > b.second);
}

void solve(const int n) {
  vector<pair<int, int>> seq(n);
  for (int i = 0; i < n; i++) cin >> seq[i].first >> seq[i].second;

  sort(seq.rbegin(), seq.rend(), cmp);

  vector<int> lis;
  lis.push_back(0);
  for (int i = 0; i < n; i++) {
    int is = 1;
    auto ub = upper_bound(lis.begin(), lis.end(), seq[i].second);
    if (ub != lis.end() || seq[i].second >= lis.back()) is = ub - lis.begin();
    if (is >= lis.size())
      lis.push_back(seq[i].second);
    else if (lis[is] > seq[i].second)
      lis[is] = seq[i].second;
  }

  cout << lis.size() - 1 << endl;
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
