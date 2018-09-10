#include <bits/stdc++.h>
using namespace std;

char a[50001];
char b[50001];
unsigned long long pm[26][50001];
unsigned long long v[50001];

int main() {
  scanf("%s%s", a, b);
  int n = strlen(a);
  int m = strlen(b);
  if (n < m) {
    swap(a, b);
    swap(n, m);
  }
  const int sz = (n + 63) / 64;

  unsigned long long bitpos = 1;
  int vetpos = 0;
  for (int i = 0; i < n; i++) {
    pm[a[i] - 'a'][vetpos] |= bitpos;
    bitpos <<= 1;
    if (!bitpos) {
      bitpos = 1;
      vetpos++;
    }
  }

  for (int j = 0; j < m; j++) {
    const char c = b[j] - 'a';
    unsigned long long carry = 1;
    for (int i = 0; i < sz; i++) {
      const unsigned long long u = (v[i] | pm[c][i]);
      const unsigned long long tmp_carry = (v[i] >> 63);
      const unsigned long long mask = (u - ((v[i] << 1) | carry));
      v[i] = (u & (~mask));
      carry = (mask > u ? 1 : 0) + tmp_carry;
    }
  }

  int ans = 0;
  for (int i = 0; i < sz; i++)
    while (v[i]) {
      v[i] &= v[i] - 1;
      ans++;
    }

  printf("%d\n", ans);
}
