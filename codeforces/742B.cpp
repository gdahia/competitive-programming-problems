#include <bits/stdc++.h>
using namespace std;

#define N_MAX 2*100001

int main() {
	int hist[N_MAX];
	memset(hist, 0, sizeof hist);
	int n, x;
	cin >> n >> x;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (x) {
			ans += hist[a];
			hist[(x ^ a)]++;
		}
		else
			ans += hist[a]++;
	}
	cout << ans << endl;
}
