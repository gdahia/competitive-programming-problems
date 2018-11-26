#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  while (n > 0 && k > 0) {
    const int rem = n % 10;
    if (rem == 0) {
      n /= 10;
      k--;
    } else if (k >= rem) {
      k -= rem;
      n -= rem;
    } else {
      n -= k;
      k = 0;
    }
  }

  cout << n << endl;
}
