#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, n1, n2;
	cin >> n >> n1 >> n2;
	if (n1 > n2)
		swap(n1, n2);
	vector<long long> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.rbegin(), a.rend());
	long double mean1 = 0, mean2 = 0;
	for (int i = 0; i < n1; i++)
		mean1 += a[i];
	for (int i = n1; i < n1 + n2; i++)
		mean2 += a[i];
	mean1 /= n1;
	mean2 /= n2;
	cout << fixed << setprecision(9) << mean1 + mean2 << endl;
}
