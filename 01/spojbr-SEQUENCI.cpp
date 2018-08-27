#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

void solve(const int d, const int ndt) {
  vector<int> as(d);
  for (int i = 0; i < d; i++) cin >> as[i];

  bool a_seq = true;
  for (int i = 1; i < d; i++)
    if (as[i - 1] >= as[i]) a_seq = false;

  const int max_a = as.back();
  vector<int> ans(max_a + 1, 0);
  ans[0] = 1;
  for (const int a : as)
    for (int i = max_a - a; i >= 0; i--) ans[i + a] += ans[i];

  for (const int a : as)
    if (ans[a] > 1) a_seq = false;

  cout << "Case #" << ndt << ":";
  for (const int a : as) cout << " " << a;
  cout << endl;
  cout << "This is " << (a_seq ? "" : "not ") << "an A-sequence." << endl;
}

int main() {
  int d, ndt = 1;
  while (cin >> d) solve(d, ndt++);
}
