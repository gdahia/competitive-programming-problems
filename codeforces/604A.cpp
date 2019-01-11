#include <bits/stdc++.h>

using namespace std;

int main() {
	int m[5], w[5], h[2], x[5] = {500, 1000, 1500, 2000, 2500};
	for (int i = 0; i < 5; i++)
		cin >> m[i];
	for (int i = 0; i < 5; i++)
		cin >> w[i];
	cin >> h[0] >> h[1];
	int ans = 100*h[0] - 50*h[1];
	for (int i = 0; i < 5; i++) {
		ans += max((3*x[i])/10, x[i] - (x[i]/250)*m[i] - 50*w[i]);
	}
	cout << ans << endl;
	return 0;
}