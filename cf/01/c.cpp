#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> seq(n);
  for (int& i : seq) cin >> i;

  sort(seq.begin(), seq.end());

  if (k == 0) {
    if (seq[0] == 1)
      cout << -1 << endl;
    else
      cout << seq[0] - 1 << endl;
  } else if (seq[k - 1] != seq[k])
    cout << seq[k - 1] << endl;
  else
    cout << -1 << endl;
}
