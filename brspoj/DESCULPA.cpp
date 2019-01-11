#include <iostream>
#include <vector>
using namespace std;

void solve(const int c, const int f, const int ndt) {
  vector<int> vs(f);
  vector<int> ws(f);
  for (int i = 0; i < f; i++) cin >> ws[i] >> vs[i];

  vector<int> ans(c + 1, 0);
  for (int i = 0; i < f; i++) {
    const int v = vs[i];
    const int w = ws[i];
    for (int j = c - w; j >= 0; j--)
      if (ans[j + w] < ans[j] + v) ans[j + w] = ans[j] + v;
  }

  cout << "Teste " << ndt << endl;
  cout << ans[c] << endl;
  cout << endl;
}

int main() {
  int c, f, t = 1;
  while (cin >> c >> f, c | f) solve(c, f, t++);
}
