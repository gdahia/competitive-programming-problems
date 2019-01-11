#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main() {
	int n;
	cin >> n;
	int p[n], m[n + 2], unp[n + 2];
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		unp[p[i]] = i;
	}
	memset(m, 0, sizeof m);
	int lis[n];
	lis[n - 1] = 1;
	m[p[n - 1]] = 1;
	for (int i = n - 2; i >= 0; i--) {
		if (m[p[i] + 1])
			lis[i] = lis[unp[p[i] + 1]] + 1;
		else
			lis[i] = 1;
		m[p[i]] = 1;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, lis[i]);
	ans = n - ans;
	cout << ans << endl;
	return 0;
}