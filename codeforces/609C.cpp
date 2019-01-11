#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main() {
	int n;
	cin >> n;
	int c[20010], m, g = -1;
	memset(c, 0, sizeof c);
	for (int i = 0; i < n; i++) {
		cin >> m;
		c[m]++;
		g = max(g, m);
	}
	int l = 0, r = g, ans = 0;
	while (r > l + 1) {
		if (c[r] > c[l]) {
			c[r - 1] += c[l];
			c[l + 1] += c[l];
			ans += c[l];
			c[r] -= c[l];
			l++;
		}
		else {
			c[r - 1] += c[r];
			c[l + 1] += c[r];
			ans += c[r];
			c[l] -= c[r];
			r--;
		}
	}
	cout << ans << endl;
	return 0;
}
