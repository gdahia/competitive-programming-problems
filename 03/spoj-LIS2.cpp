#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct first_cmp {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
    return a.first < b.first || (a.first == b.first && a.second > b.second);
  }
};

bool total_ord(const pair<int, int>& a, const pair<int, int>& b) {
  return a.first < b.first && a.second < b.second;
}

bool cmp(const set<pair<int, int>, first_cmp>& s, const pair<int, int>& p) {
  auto lb = s.lower_bound(p);
  return (lb != s.begin() && total_ord(*(--lb), p));
}

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> seq(n);
  for (pair<int, int>& p : seq) cin >> p.first >> p.second;

  vector<set<pair<int, int>, first_cmp>> lis;
  lis.push_back({{-1123456789, -1123456789}});
  for (int i = 0; i < n; i++) {
    int is = 1;
    auto lb = lower_bound(lis.begin(), lis.end(), seq[i], cmp);
    if (lb != lis.end() || cmp(lis.back(), seq[i])) is = lb - lis.begin();
    if (is >= lis.size())
      lis.push_back({seq[i]});
    else {
      auto lb = lis[is].lower_bound(seq[i]);
      auto ub = lb;
      while (ub != lis[is].end() && ub->second >= seq[i].second) ub++;
      lis[is].erase(lb, ub);
      lis[is].insert(seq[i]);
    }
  }

  cout << lis.size() - 1 << endl;
}
