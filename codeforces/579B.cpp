# include <bits/stdc++.h>

using namespace std;

struct Trio {
	int a, b, c;
	bool operator < (const Trio & rhs) const {
		return c > rhs.c;
	}
};

int main() {
	int n, a;
	scanf("%d", &n);
	int N = n << 1;
	int time[N];
	vector <Trio> todo;
	Trio tmp;
	for (int i = 0; i < N; i++)
		time[i] = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			scanf("%d", &tmp.c);
			tmp.b = j;
			tmp.a = i;
			//printf("%d-%d = %d\n", tmp.a, tmp.b, tmp.c);
			todo.push_back(tmp);
		}
	}
	sort( todo.begin(), todo.end() );
	int tam = todo.size();
	for (int i = 0; i < tam && n; i++) {
		//printf("%d-%d = %d\n", todo[i].a, todo[i].b, todo[i].c);
		if (!time[ todo[i].a ] && !time[ todo[i].b ]) {
			time[ todo[i].a ] = todo[i].b + 1;
			time[ todo[i].b ] = todo[i].a + 1;
			n--;
		}
	}
	for (int i = 0; i < N; i++)
		printf("%d%c", time[i], i == N - 1 ? '\n' : ' ');
	return 0;
}
