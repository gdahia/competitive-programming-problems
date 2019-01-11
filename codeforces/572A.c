#include <stdio.h>

int main () {
	int n[2];
	scanf("%d%d", &n[0], &n[1]);
	int k, m, A[n[0]], B[n[1]];
	scanf("%d%d", &k, &m);
	int i;
	for (i = 0; i < n[0]; i++)
		scanf("%d", &A[i]);
	for (i = 0; i < n[1]; i++)
		scanf("%d", &B[i]);
	int bmin = B[ n[1] - m], amax = A[k - 1];
	//printf("bmin = %d <?> %d = amax\n", bmin, amax);
	if (amax < bmin)
		printf("YES");
	else
		printf("NO");
	printf("\n");
	return 0;
}
