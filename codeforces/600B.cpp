#include <bits/stdc++.h>
#define pb push_back
#define ms(a, b) memset((a), b, sizeof(a))

using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int a[n], b;
	for (int i = 0; i < n; i++) {
		scanf("%d", a+i);
	}
	sort(a, a+n);
	for (int i = 0; i < m; i++) {
		scanf("%d", &b);
		int r = n, l = 0, m;
		while (r > l) {
			m = (l+r) >> 1;
			if (a[m] > b) {
				r = m;
			}
			else {
				l = m + 1;
			}
		}
		printf("%d ", r);
	}
	return 0;
}
