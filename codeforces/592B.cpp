#include <bits/stdc++.h>
#define pb push_back
#define ms(a, b) memset((a), b, sizeof(a))

using namespace std;

int main() {
	long long n;
	cin >> n;
	long long ans = n - 2 + 2*(n - 3);
	for (int i = 3; i < n; i++) {
		ans += n - 4;
	}
	cout << ans << endl;
	return 0;
}