#include <bits/stdc++.h>
using namespace std;

void solve(const string& s, const string& p) {
  const int n = s.size();
  const int m = p.size();
  vector<int> pi(m);
  pi[0] = 0;
  int k = 0;
  for (int i = 1; i < m; i++) {
    while (k > 0 && p[i] != p[k]) k = pi[k - 1];

    if (p[i] == p[k]) k++;

    pi[i] = k;
  }

  k = 0;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    while (k > 0 && s[i] != p[k]) k = pi[k - 1];

    if (s[i] == p[k]) k++;

    if (k == m) {
      ans.push_back((i + 1) - (k - 1));
      k = pi[k - 1];
    }
  }

  if (ans.empty())
    cout << "Not Found" << endl;
  else {
    cout << ans.size() << endl;
    for (const int x : ans) cout << x << " ";
    cout << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s, p;
    cin >> s >> p;
    solve(s, p);
    if (t) cout << endl;
  }
}
