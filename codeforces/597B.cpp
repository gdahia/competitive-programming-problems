#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	pair <int, int> o[n];
	for (int i = 0; i < n; i++)
		cin >> o[i].second >> o[i].first;
	sort(o, o+n);
	int last = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (o[i].second > last) {
			last = o[i].first;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}