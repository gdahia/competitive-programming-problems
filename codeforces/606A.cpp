#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main() {
	int a,b,c,x,y,z, extra = 0;
	cin >> a >> b >> c >> x >> y >> z;
	if (a > x) {
		extra += (a - x)/2;
	}
	if (c > z) {
		extra += (c - z)/2;
	}
	if (b > y) {
		extra += (b - y)/2;
	}
	if (a < x && extra + a >= x) {
		extra = max(0, extra - x + a);
		a = x;
	}
	if (b < y && extra + b >= y) {
		extra = max(0, extra - y + b);
		b = y;
	}
	if (c < z && extra + c >= z) {
		c = z;
	}
	if (a >= x && b >= y && c >= z)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	return 0;
}