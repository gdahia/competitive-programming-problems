# include <bits/stdc++.h>

using namespace std;

int main() {
	int n, t;
	scanf("%d%d", &n, &t);
	if (n == 1 && t < 10) {
		printf("%d\n", t);
		return 0;
	}
	if (t < 10)
		printf("%d%0*d\n", t, n - 1, t);
	else if (n > 1) {
		putchar('1');
		for (int i = 1; i < n; i++) {
			putchar('0');
		}
		putchar('\n');
	}
	else
		puts("-1");
	return 0;
}