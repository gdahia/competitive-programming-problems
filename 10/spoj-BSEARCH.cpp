#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  scanf("%d%d", &n, &q);

  vector<int> v(n);
  for (int& i : v) scanf("%d", &i);

  while (q--) {
    int x;
    scanf("%d", &x);

    auto lb = lower_bound(v.begin(), v.end(), x);
    if (lb != v.end() && *lb == x)
      printf("%d\n", lb - v.begin());
    else
      puts("-1");
  }
}
