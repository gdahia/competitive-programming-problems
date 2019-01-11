#include <bits/stdc++.h>

using namespace std;

int main() {
	int l, p, q;
	scanf("%d%d%d", &l, &p, &q);
	p *= -1;
	double ans = p*l;
	ans /= q - p;
	if (ans < 0) ans *= -1;
	printf("%lf\n", ans);
	return 0;
}
