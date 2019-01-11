#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int s, m;
	bool operator < (const Edge & rhs) const {
		return m > rhs.m;
	}
};

struct Menores {
	int i, c;
	bool operator < (const Menores & rhs) const {
		return c < rhs.c;
	}
};

struct Maiores {
	int i, c;
	bool operator < (const Maiores & rhs) const {
		return c > rhs.c;
	}
};

int main() {
	int n, d;
	long long res = 0, total = 0;
	scanf("%d%d", &n, &d);
	Edge fri[n];
	for (int i = 0; i < n; i++)
		scanf("%d%d", &fri[i].m, &fri[i].s); 
	sort(fri, fri + n);
	Edge *l, *r;
	l = r = &fri[0];
	Maiores prox;
	Menores next;
	priority_queue <Menores> menor;
	priority_queue <Maiores> maior;
	prox.i = next.i = 0;
	prox.c = next.c = fri[0].m;
	maior.push(prox);
	menor.push(next);
	while (r <= &fri[n - 1]) {
		while (r <= &fri[n - 1] && llabs(r->m - menor.top().c) < d && llabs(r->m - maior.top().c) < d) {
			total += r->s;
			next.i = prox.i = r - &fri[0];
			next.c = prox.c = r->m;
			maior.push(prox);
			menor.push(next);
			r++;
		}
		if (total > res)
			res = total;
		total -= l->s;
		l++;
		prox.i = next.i = l - &fri[0];
		prox.c = next.c = l->m;
		menor.push(next);
		maior.push(prox);
		next = menor.top();
		while (next.i < l - &fri[0]) {
			menor.pop();
			next = menor.top();
		}
		prox = maior.top();
		while (prox.i < l - &fri[0]) {
			maior.pop();
			prox = maior.top();
		}
		if (r < l)
			r = l;
	}
	cout << res << endl;
	return 0;
}
