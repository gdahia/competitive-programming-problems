#include <stdio.h>
#include <bitset>
#include <vector>
using namespace std;

int main() {
  int n, q;
  scanf("%d%d", &n, &q);

  vector<int> as(n);
  for (int i = 0; i < n; i++) scanf("%d", &as[i]);

  bitset<100001> ans, tmp;
  ans[0] = true;
  for (const int a : as) {
    tmp |= ans;
    tmp <<= a;
    ans |= tmp;
  }

  vector<int> prefix(100001);
  prefix[0] = ans[0];
  for (int i = 1; i <= 100000; i++) prefix[i] = prefix[i - 1] + ans[i];

  for (int i = 0; i < q; i++) {
    int b, e;
    scanf("%d%d", &b, &e);

    printf("%d\n", prefix[e] - prefix[b - 1]);
  }
}
