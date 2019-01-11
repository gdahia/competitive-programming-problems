# include <stdio.h>
# include <stdlib.h>
# define min(a,b) (a < b ? a : b)

int main () {
	int n, m, resposta;
	scanf("%d%d", &n, &m);
	if (n == 1)
		resposta = 1;
	else if (n - m > m - 1)
		resposta = m + 1;
	else
		resposta = m - 1;
	printf("%d\n", resposta);
	return(0);
}
