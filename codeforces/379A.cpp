#include <iostream>
using namespace std;

int main() {
	int a, b, ans;
	cin >> a >> b;
	ans = a;
	int r = a;
	while (r/b) {
		a = r;
		r = 0;
		while (a) {
			r += a % b;
			a /= b;
			ans += a;
		}
	}
	cout << ans << endl;
	return 0;
}