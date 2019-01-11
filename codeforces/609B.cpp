#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	long long g[m + 1];
	memset(g, 0, sizeof g);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		g[a]++;
	}
	long long ans = 0;
	for (int i = 1; i < m; i++) {
		for (int j = i + 1; j <= m; j++)
			ans += g[i]*g[j];
	}
	cout << ans << endl;
	return 0;
}
