#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

void solve(const int x, const int y, const int n, const int ndt) {
  vector<int> vs(n);
  int total = 0;
  for (int i = 0; i < n; i++) {
    cin >> vs[i];
    total += vs[i];
  }

  const int y_rem = (x - y + total) / 2;
  bitset<10001> mask, tmp;
  mask[0] = true;
  for (const int v : vs) {
    tmp |= mask;
    tmp <<= v;
    mask |= tmp;
  }

  cout << "Teste " << ndt << endl;
  if (2 * y_rem == x - y + total && mask[y_rem])
    cout << "S" << endl;
  else
    cout << "N" << endl;
  cout << endl;
}

int main() {
  int x, y, n;
  int ndt = 1;
  while (cin >> x >> y >> n, x | y | n) solve(x, y, n, ndt++);
}
