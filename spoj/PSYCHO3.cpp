#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

bool psycho(int n) {
  int odds = 0;
  int evens = 0;
  for (int i = 2; n > 1; i++) {
    int power = 0;
    while (n % i == 0) {
      n /= i;
      power++;
    }
    if (power > 0)
      if (power % 2 == 0)
        evens++;
      else
        odds++;
  }

  if (odds < evens) return true;
  return false;
}

void solve(const int n, const int k) {
  vector<int> vs;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (psycho(x)) vs.push_back(x);
  }

  bitset<100000> ans, tmp;
  ans[0] = true;
  for (const int v : vs) {
    tmp |= ans;
    tmp <<= v;
    ans |= tmp;
  }

  if (ans[k])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    solve(n, k);
  }
}
