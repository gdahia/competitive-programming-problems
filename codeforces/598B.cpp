#include <bits/stdc++.h>
using namespace std;

void cycle(int l, int r, int k, string & s) {
	string t;
	for (int i = r - k + 1; i <= r; ++i)	{
		t += s[i];
	}
	for (int i = r; i >= l + k; --i)	{
		s[i] = s[i - k];
	}
	for (int i = 0; i < k; ++i)	{
		s[i + l] = t[i];
	}
}

int main() {
	string s;
	cin >> s;
	int m;
	scanf("%d", &m);
	while (m--) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		k %= r - l + 1;
		l--;
		r--;
		cycle(l, r, k, s);
	}
	cout << s << endl;
	return 0;
}