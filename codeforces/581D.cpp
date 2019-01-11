#include <bits/stdc++.h>

using namespace std;

struct par {
	int x, y, i, tot;
};

int main() {
	par logo[3];
	int area = 0, sqareat;
	for (int i = 0; i < 3; i++) {
		scanf("%d%d", &logo[i].x, &logo[i].y);
		area += logo[i].tot = logo[i].x*logo[i].y;
		logo[i].i = i;
	}
	sqareat = sqrt(area);
	if (sqareat*sqareat != area)
		puts("-1");
	else {
		char billboard[sqareat][sqareat];
		memset(billboard, 'p', sizeof(billboard));
		int conc = 3, ender = 0, i, m, n, *x, *y, diml = sqareat, dimc = sqareat, feito[3] = {0, 0, 0};
		for (int i = 0; conc && ender < 6; i++, i %= 3) {
			char letra = logo[i].i + 'A';
			if (feito[i] > 0) continue;
			if (logo[i].x == diml) {
				x = &n;
				y = &m;
				dimc -= logo[i].y;
			}
			else if (logo[i].y == dimc) {
				x = &m;
				y = &n;
				diml -= logo[i].x;
			}
			else if (logo[i].x == dimc) {
				x = &m;
				y = &n;
				diml -= logo[i].y;
			}
			else if (logo[i].y == diml) {
				x = &n;
				y = &m;
				dimc -= logo[i].x;
			}
			else {
				ender++;
				continue;
			}
			//printf("logo(%d), x= %d, y = %d, diml = %d, dimc = %d\n", i + 1, logo[i].x, logo[i].y, diml, dimc);
			feito[i] = 1;
			conc--;
			for (m = 0; logo[i].tot && m < sqareat; m++) {
				for (n = 0; logo[i].tot && n < sqareat; n++) {
					if (billboard[*x][*y] == 'p') {
						billboard[*x][*y] = letra;
						logo[i].tot--;
					}
				}
			}
			/*for (int k = 0; k < sqareat; k++) {
				for (int l = 0; l < sqareat; l++) {
					printf("%c", billboard[k][l]);
				}
				puts("");
			}
			puts("");*/
		}
		if (!conc) {
			printf("%d\n", sqareat);
			for (int i = 0; i < sqareat; i++) {
				for (int j = 0; j < sqareat; j++) {
					printf("%c", billboard[i][j]);
				}
				puts("");
			}
		}
		else
			puts("-1");
	}
	return 0;
}