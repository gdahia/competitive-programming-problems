# include <bits/stdc++.h>

using namespace std;

int main() {
	int n, res = 0, i;
	scanf("%d", &n);
	int a[n], curr = 0, total = n;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	i = 0;
	int dir = 0;
	while (total) {
		if (i < 0) i++;
		for (; i < n && total; i++) {
			if (a[i] <= curr) {
				curr++;
				// printf("dir grab %d = %d\ncurr = %d\n", i + 1, a[i], curr);
				a[i] = 0x3f3f3f3f;
				total--;
				if (dir) {
					res++;
					dir = 0;
					// puts("res++");
				}
			}
		}
		if (i == n) i--;
		for (; i >= 0 && total; i--) {
			if (a[i] <= curr) {
				curr++;
				// printf("rev grab %d = %d\n, curr = %d\n", i + 1, a[i], curr);
				a[i] = 0x3f3f3f3f;
				total--;
				if (!dir) {
					res++;
					dir = 1;
					// puts("res++");
				}
			}
		}
	}
	printf("%d\n", res);
	return 0;
}