#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <stdlib.h>

using namespace std;

int main () {
	int n, s;
	scanf("%d %d\n", &n, &s);
	int i, p, q;
	long long order[100001][2];
	char d;
	for (i = 0; i < 100001; i++)
		order[i][0] = order[i][1] = 0;
	for (i = 0; i < n; i++) {
		d = getchar();
		while (d != 'B' && d != 'S')
			d = getchar();
		scanf("%d %d",&p, &q);
		if (d == 'B')
			order[p][1] += q;
		else
			order[p][0] += q;
	}
	int j, k;
	vector < int > indice;
	for (i = 0, k = 0; k < s && i < 100001; i++)
		if (order[i][0])
			indice.push_back(i), k++;
	int tam = indice.size() - 1;
	for (int r = tam; r >= 0; r--)
		cout << "S" << " " << indice[r] << " " << order[indice[r]][0] << endl, k++;
	for (i = 100000, k = 0; k < s && i >= 0; i--)
		if (order[i][1])
			cout << "B" << " " << i << " " << order[i][1] << endl, k++;
	
	return 0;
}
