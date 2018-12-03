#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> seq;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    seq.emplace_back(x, i + 1);
  }

  sort(seq.rbegin(), seq.rend());

  vector<int> sseq;
  sseq.push_back(0);
  int ans = 0;
  for (int i = 0; i < k; i++) {
    ans += seq[i].first;
    sseq.push_back(seq[i].second);
  }

  sort(sseq.begin(), sseq.end());

  cout << ans << endl;
  ans = 0;
  for (int i = 1; i < k; i++) cout << sseq[i] - sseq[i - 1] << " ";
  cout << n - sseq[k - 1] << endl;
}
