# include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int b[n + 1], a[n][2], pos[n + 1], pre[n + 1];
	for (int j = 0; j < 2; j++)
		for (int i = 1; i < n; i++) 
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}
	pos[n] = 0;
	for (int i = n - 1; i > 0; i--)
		pos[i] = a[i][1] + pos[i + 1];
	pre[1] = 0;
	for (int i = 2; i <= n; i++)
		pre[i] = a[i - 1][0] + pre[i - 1];
	/*for (int i = 1; i <= n; i++) {
		printf("pre[%d] = %d\n", i, pre[i]);
		printf("pos[%d] = %d\n", i, pos[i]);
	}*/
	int minida = b[n] + pre[n], ida = n;
	for (int i = 1; i < n; i++) {
		if (minida > b[i] + pos[i] + pre[i]) {
			ida = i;
			minida = b[i] + pos[i] + pre[i];
		}
	}
	int minvolta = 0x3f3f3f3f;
	if (minida > b[1] + pos[1]) {
		ida = 1;
		minida = b[1] + pos[1];
	}
	for (int i = 1; i <= n; i++) {
		if (i != ida)
			minvolta = min(minvolta, b[i] + pre[i] + pos[i]);
	}
	printf("%d\n", minida + minvolta);
	return 0;
}