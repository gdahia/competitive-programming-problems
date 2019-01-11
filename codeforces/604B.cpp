#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, ans = -1;
	cin >> n >> k;
	int s[n];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		ans = max(ans,s[i]);
	}
	if (2*k > n) n -= 2*k - n;
	for (int i = 0; i < n; i++)
			ans = max(ans, s[i]+s[n - i - 1]);
	cout << ans << endl;
}