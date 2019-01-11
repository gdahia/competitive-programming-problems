# include <bits/stdc++.h>

using namespace std;

int main() {
	int n, n2, a, b;
	scanf("%d", &n);
	n2 = n*n;
	int vert[n], hor[n];
	vector<int> res;
	memset(vert, 0, sizeof(vert));
	memset(hor, 0, sizeof(hor));
	for (int i = 1; i <= n2; i++) {
		scanf("%d%d", &a, &b);
		a--, b--;
		// cout << hor[a] << " " << vert[b] << endl;
		if (!hor[a] && !vert[b]) {
			res.push_back(i);
			hor[a] = 1;
			vert[b] = 1;
		}
	}
	int len = res.size();
	for (int i = 0; i < len; i++) {
		printf("%d%c", res[i], i == len - 1 ? '\n' : ' ');
	}
	return 0;
}