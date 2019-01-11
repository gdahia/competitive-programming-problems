#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n, greater<int>());
	int ans = 0;
	for (int i = 0; i < n && m > 0; i++) {
		m -= a[i];
		ans++;
	}
	cout << ans << endl;
	return 0;
}
