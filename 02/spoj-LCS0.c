#include <stdio.h>
#include <string.h>

int readline(char* str) {
  int i = 0;
  char ch;
  while ((ch = getchar()) != '\n') {
    str[i++] = ch;
  }
  str[i] = '\0';
  return i;
}

int main() {
  char a[50001], b[50001];
  const int n = readline(a);
  const int m = readline(b);

  int a_char_pos[26][50001];
  int cursor[26];
  for (int i = 0; i < 26; i++) cursor[i] = 0;
  for (int i = 0; i < n; i++) {
    const char c = a[i] - 'a';
    a_char_pos[c][cursor[c]++] = i;
  }

  int aux[n + 1];
  int ans = 0;
  for (int i = 0; i < m; i++) {
    const char c = b[i] - 'a';
    for (int j = cursor[c] - 1; j >= 0; j--) {
      int lis = 1;
      int l = 1, r = ans;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (aux[mid] <= a_char_pos[c][j])
          l = mid + 1;
        else
          r = mid - 1;
      }
      lis = l;
      if (lis == ans + 1)
        aux[ans++] = a_char_pos[c][j];
      else if (aux[lis] > a_char_pos[c][j])
        aux[lis] = a_char_pos[c][j];
    }
  }

  printf("%d\n", ans);
}
