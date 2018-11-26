#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;

  map<pair<char, char>, int> q;
  for (int i = 0; i < n - 1; i++) {
    const char c1 = s[i];
    const char c2 = s[i + 1];

    q[{c1, c2}]++;
  }

  int ans = -1;
  char ans_c1;
  char ans_c2;
  for (const pair<pair<char, char>, int>& p : q)
    if (p.second > ans) {
      ans = p.second;
      tie(ans_c1, ans_c2) = p.first;
    }

  cout << ans_c1 << ans_c2 << endl;
}
