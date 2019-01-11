# include <bits/stdc++.h>

using namespace std;

int main() {
	int n, x, res = 0;
	scanf("%d%d", &n, &x);
	for (int i = n; i && x/i <= n; i--) {
		if ( !(x%i) ) res++;
	}
	printf("%d\n", res);
	return 0;
}
