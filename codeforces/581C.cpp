#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int curr;
	priority_queue < pair <int, int> > fila;
	pair <int, int> a;
	long long res = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a.second);
		res += a.second/10;
		a.first = a.second % 10;
		if (a.second < 100)	fila.push(a);
	}
	while (k && !fila.empty()) {
		a = fila.top();
		fila.pop();
		curr = 10 - a.first;
		if (curr > k) {
			break;
		}
		else {
			res += (a.second + curr)/10 - (a.second)/10;
			k -= curr;
			a.second += curr;
			a.first = a.second % 10;
			if (a.second < 100)	fila.push(a);
		}
	}
	cout << res << endl;
	return 0;
}