#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	long long n, logn;
	scanf("%d", &t);
	while (t--) {
		cin >> n;
		long long ans = ((n + 1)*(n)) >> 1;
		for (logn = 0; n >> logn; logn++);
		ans -= 2*( (1 << logn) - 1);
		cout << ans << endl;
	}
	return 0;
}