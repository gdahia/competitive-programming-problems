#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int h[n], suffix[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
		suffix[i] = 0;
	}
	suffix[n - 1] = h[n - 1];
	for (int i = n - 2; i >= 0; i--)
		suffix[i] = max(suffix[i + 1], h[i]);
	for (int i = 0; i < n - 1; i++) {
		printf("%d ", max(suffix[i + 1] - h[i] + 1, 0));
	}
	/*for (int i = 0; i < n; i++) {
		printf("%d ", suffix[i]);
	}*/
	puts("0");
	return 0;
}