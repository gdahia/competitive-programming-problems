#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int res = 1, combo = 1, seq[n];
	scanf("%d", &seq[0]);
	for (int i = 1; i < n; i++) {
		scanf("%d", &seq[i]);
		if (seq[i] >= seq[i - 1])
			combo++;
		else {
			if (combo > res)
				res = combo;
			combo = 1;
		}
	}
	if (combo > res)
		res = combo;
	printf("%d\n", res);
	return 0;
}
