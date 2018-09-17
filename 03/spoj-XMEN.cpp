#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve(const int n) {
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    pos[v - 1] = i;
  }

  vector<int> seq(n);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    seq[i] = pos[v - 1];
  }

  vector<int> lis;
  lis.push_back(-1);
  for (int i = 0; i < n; i++) {
    int is = 1;
    auto lb = lower_bound(lis.begin(), lis.end(), seq[i]);
    if (lb != lis.end() || seq[i] > lis.back()) is = lb - lis.begin();
    if (is < lis.size())
      lis[is] = min(lis[is], seq[i]);
    else
      lis.push_back(seq[i]);
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
