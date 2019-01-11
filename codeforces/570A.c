# include <stdio.h>
# include <stdlib.h>
# define min(a,b) (a < b ? a : b)

int main () {
	int n, m;
	scanf("%d%d", &n, &m);
	int urna[100], vencedor, cidade[100], granv = 0, i, j, a;
	for (j = 0; j < 100; j++)
		cidade[j] = 0;
	for (i = 0; i < m; i++) {
		vencedor = 0;
		for (j = 0; j < 100; j++)
			urna[j] = 0;
		for (j = 0; j < n; j++) {
			scanf("%d", &a);
			urna[j] += a;
			if (urna[j] > urna[ vencedor ])
				vencedor = j;
			else if (urna[j] == urna[ vencedor ])
				vencedor = min(j, vencedor);
		}
		if (++cidade[ vencedor ] > cidade[granv] )
			granv = vencedor;
		else if (cidade[ vencedor ] == cidade[granv])
			granv = min(granv, vencedor);
	}
	printf("%d\n", granv + 1);
	return(0);
}
