#include <bits/stdc++.h>
using namespace std;

struct mat {
	long long i11, i12, i21, i22;
	
	mat(long long i11, long long i12, long long i21, long long i22)
		: i11(i11), i12(i12), i21(i21), i22(i22) {}
	
	mat operator * (const mat & b) const {
		return mat(i11*b.i11 + i12*b.i21, i11*b.i12 + i12*b.i22, i21*b.i11 + i22*b.i21, i21*b.i12 + i22*b.i22);
	}
};

mat fib(long long n) {
	if (n == 0) return mat(0, 0, 0, 0);
	if (n == 1) return mat(1, 1, 1, 0);
	mat f = fib(n >> 1);
	if (n & 1)
		return f*f*mat(1, 1, 1, 0);
	return f*f;
}

int main() {
	long long n;
	cin >> n;
	long long l = 0, r = 89;
	while (l <= r) {
		long long m = (l + r) >> 1;
		if (fib(m + 2).i12 - 1 >= n)
			r = m - 1;
		else
			l = m + 1;
	}
	cout << l - 1 << endl;
}
