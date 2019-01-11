# include <bits/stdc++.h>

int main() {
	int x, b = 1, soma = 0, resposta;
	scanf("%d", &x);
	for (resposta = 0; soma < x; resposta++) {
		long double a = logl(x - soma)/logl(2);
		b = 1 << ( (int) a );
		soma += b;
	}
	printf("%d\n", resposta);
	return 0;
}
