#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve(const int n) {
  vector<int> perm(n);
  vector<int> idx(n + 2);
  for (int i = 0; i < n; i++) {
    cin >> perm[i];
    idx[perm[i]] = i;
  }

  vector<int> lis;
  vector<int> seq;
  lis.push_back(-1);
  for (int i = 0; i < n; i++) {
    int is = 1;
    auto lb = lower_bound(lis.begin(), lis.end(), perm[i]);
    if (lb != lis.end() || perm[i] > lis.back()) is = lb - lis.begin();
    if (is < lis.size())
      lis[is] = min(lis[is], perm[i]);
    else
      lis.push_back(perm[i]);

    seq.push_back(is);
  }

  const int llis = lis.size() - 1;
  vector<int> is(n, 1);
  is.push_back(llis + 1);
  vector<int> rev(llis + 1, 0);
  rev.push_back(n + 1);
  idx[n + 1] = is.size() - 1;
  vector<int> ans;
  for (int i = n - 1; i >= 0; i--) {
    if (rev[seq[i] + 1] > perm[i]) {
      is[i] = is[idx[rev[seq[i] + 1]]];
      rev[seq[i]] = max(rev[seq[i]], perm[i]);
      if (is[i] == llis + 1) ans.push_back(perm[i]);
    }

    // cout << "perm: " << endl;
    // for (int j : perm) cout << j << " ";
    // cout << endl;

    // cout << "seq: " << endl;
    // for (int j : seq) cout << j << " ";
    // cout << endl;

    // cout << "is: " << endl;
    // for (int j : is) cout << j << " ";
    // cout << endl;

    // cout << "rev: " << endl;
    // for (int j : rev) cout << j << " ";
    // cout << endl << endl;
  }

  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (const int i : ans) cout << i << " ";
  cout << endl;
}

int main() {
  int t = 10;
  while (t--) {
    int n;
    cin >> n;
    solve(n);
  }
}
