#include<bits/stdc++.h>
using namespace std;
#define N_MAX 100
int uf[N_MAX + 1], sz[N_MAX + 1];

int find(int v) {
	if (v == uf[v])
		return v;
	else
		return uf[v] = find(uf[v]);
}

void merge(int v, int u) {
	int a = find(v), b = find(u);
	if (a != b) {
		if (sz[a] < sz[b]) {
			uf[a] = b;
			sz[b] += sz[a];
		}
		else {
			uf[b] = a;
			sz[a] += uf[b];
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		uf[i] = i;
		sz[i] = 1;
	}
	vector<int> group[m + 1];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int l;
			cin >> l;
			group[l].push_back(i);
		}
		if (k == 0)
			group[0].push_back(i);
	}
	for (int i = 1; i <= m; i++) {
		for (int v : group[i])
			merge(v, group[i][0]);
	}
	set<int> ans;
	for (int i = 1; i <= n; i++)
		ans.insert(find(i));
	int s = ans.size() - (ans.size() != group[0].size());
	cout << max(0, s) << endl;
}
