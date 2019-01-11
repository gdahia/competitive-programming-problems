#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long n) {
	if (!(n & 1))
		return n == 2;
	for (long long i = 3, sqrt_n = sqrt(n); i <= sqrt_n; i += 2)
		if (n % i == 0)
			return false;
	return true;
}

int main() {
	long long n;
	cin >> n;
	if (n != 2 && !(n & 1)) {
		cout << 2 << endl;
		return 0;
	}
	cout << (is_prime(n) ? 1 : is_prime(n - 2) ? 2 : 3) << endl;
}
