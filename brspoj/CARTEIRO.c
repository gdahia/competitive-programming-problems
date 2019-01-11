#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  int v[n];
  for (int i = 0; i < n; i++) scanf("%d", v + i);

  int ans = 0;
  int pos = 0;
  for (int i = 0; i < m; i++) {
    int q;
    scanf("%d", &q);

    int l = 0, r = n - 1;
    while (l <= r) {
      const int m = l + (r - l) / 2;
      if (q > v[m])
        l = m + 1;
      else
        r = m - 1;
    }

    ans += abs(l - pos);
    pos = l;
  }

  printf("%d\n", ans);
}
