#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> seq(n);
  for (int i = 0; i < n; i++) cin >> seq[i];

  vector<int> lis;
  for (int i = 0; i < n; i++) {
    int is = 1;
    for (int j = 0; j < i; j++)
      if (seq[i] > seq[j]) is = max(is, lis[j] + 1);
    lis.push_back(is);
  }

  int ans = 0;
  for (const int is : lis) ans = max(is, ans);

  cout << ans << endl;
}
