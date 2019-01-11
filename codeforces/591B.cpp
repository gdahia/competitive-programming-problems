#include <bits/stdc++.h>
#define pb push_back
#define ms(a, b) memset((a), b, sizeof(a))

using namespace std;

int main() {
	int n, m, tmp;
	char x, y;
	scanf("%d%d\n", &n, &m);
	string nme;
	cin >> nme;
	int head[26], tail[26];
	for (int i = 0; i < 26; i++) {
		head[i] = tail[i] = i;
	}
	while (m--) {
		while (x = getchar(), x < 'a' || x > 'z');
		while (y = getchar(), y < 'a' || y > 'z');
		tail[head[x - 'a']] = y - 'a';
		tail[head[y - 'a']] = x - 'a';
		tmp = head[y - 'a'];
		head[y - 'a'] = head[x - 'a'];
		head[x - 'a'] = tmp;
	}
	for (int i = 0; i < n; i++)
		nme[i] = tail[nme[i] - 'a'] + 'a';
	cout << nme << endl;
	return 0;
}