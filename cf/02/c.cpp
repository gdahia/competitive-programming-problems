#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<unsigned long long> seq(n);
  for (unsigned long long& i : seq) cin >> i;

  vector<unsigned long long> pre(n + 1);
  pre[0] = 0;
  for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + seq[i];

  vector<unsigned long long> post(n + 1);
  post[n] = 0;
  for (int i = n - 1; i >= 0; i--) post[i] = post[i + 1] + seq[i];

  int l = 0;
  int r = n - 1;
  unsigned long long ans = 0;
  while (l <= r) {
    if (pre[l] == post[r]) {
      ans = max(ans, pre[l]);
      l++;
      r--;
    } else if (pre[l] < post[r])
      l++;
    else
      r--;
  }

  cout << ans << endl;
}
