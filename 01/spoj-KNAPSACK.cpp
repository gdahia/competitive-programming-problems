#include <iostream>
#include <vector>
using namespace std;

int main() {
  int s, n;
  cin >> s >> n;

  vector<int> vs(n);
  vector<int> ws(n);
  for (int i = 0; i < n; i++) cin >> ws[i] >> vs[i];

  vector<int> ans(s + 1, 0);
  for (int i = 0; i < n; i++) {
    const int v = vs[i];
    const int w = ws[i];
    for (int j = s - w; j >= 0; j--)
      if (ans[j + w] < ans[j] + v) ans[j + w] = ans[j] + v;
  }

  cout << ans[s] << endl;
}
