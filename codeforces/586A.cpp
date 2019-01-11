# include <bits/stdc++.h>

using namespace std;

int main() {
	int n, p = 0, flag = 0, s = 0;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		if (a[i]) {
			if (p && s < 2 && s)
				p++;
			p++;
			s = 0;
		}
		else {
			s++;
		}
	}
	printf("%d\n", p);
	return 0;
}