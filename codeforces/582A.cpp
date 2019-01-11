# include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a%b);
}

int main() {
	int n;
	scanf("%d", &n);
	int n2 = n*n;
	vector<int> res;
	priority_queue <int> Gr;
	int G[n2];
	for (int i = 0; i < n2; ++i)
		scanf("%d", &G[i]);
	sort(G, G + n2, greater<int>());
	Gr.push(G[0]);
	res.push_back(G[0]);
	int a, p;
	for (int i = 1; i < n2; ++i) {
		p = Gr.top();
		while (!Gr.empty() && p > G[i]) {
			Gr.pop();
			p = Gr.top();
		}
		if (Gr.empty() || p < G[i]) {
			//printf("entered gcd calc with p = %d & G = %d\n", p, G[i]);
			int len = res.size();
			for (int j = 0; j < len; ++j) {
				a = gcd(res[j], G[i]);
				Gr.push(a);
				Gr.push(a);
			}
			Gr.push(G[i]);
			res.push_back(G[i]);
		}
		else
			Gr.pop();
	}
	int len = res.size();
	for (int i = 0; i < len; ++i)
		printf("%d ", res[i]);
	putchar('\n');
}