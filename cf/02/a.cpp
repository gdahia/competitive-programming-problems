#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> seq(n);
  for (long long& i : seq) cin >> i;

  for (long long& i : seq)
    if (i % 2 == 1) i++;

  for (long long& i : seq)
    if (i % 2 == 0) i--;

  for (const int i : seq) cout << i << " ";
  cout << endl;
}
