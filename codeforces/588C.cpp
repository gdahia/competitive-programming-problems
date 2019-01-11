#include <bits/stdc++.h>
#define pb push_back
#define ms(a, b) memset((a), b, sizeof(a))

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int t[1100001], w, ans = 0;
	ms(t, 0);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w);
		t[w]++;
	}
	for (int i = 1; i <= 1100000; i++) {
		t[i] += t[i - 1]/2;
		if (t[i - 1] % 2)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}