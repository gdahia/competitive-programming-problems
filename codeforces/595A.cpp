#include <bits/stdc++.h>
#define pb push_back
#define ms(a, b) memset((a), b, sizeof(a))

using namespace std;

int main() {
	int n, m, a, b;
	long long ans = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &a, &b);
			if (a || b) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}