#include <bits/stdc++.h>
#define pb push_back
#define ms(a, b) memset((a), b, sizeof(a))

using namespace std;

int main() {
	int n, b, menor;
	scanf("%d", &n);
	int a, ans = 0, p = 0x3f3f3f3f;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		p = min(p, b);
		ans += a*p;
	}
	printf("%d\n", ans);
	return 0;
}