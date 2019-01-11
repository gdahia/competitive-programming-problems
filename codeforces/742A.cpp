#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (!n) {
		cout << 1 << endl;
		return 0;
	}
	int ans[4] = {6, 8, 4, 2};
	cout << ans[n % 4] << endl;
}
