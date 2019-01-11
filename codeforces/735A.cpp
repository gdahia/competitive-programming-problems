#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++)
		if (s[i] == 'G') {
			bool flag = false;
			for (int j = i; !flag && j < n; j += k)
				if (s[j] == '#')
					break;
				else if (s[j] == 'T')
					flag = true;
			for (int j = i; !flag && j >= 0; j -= k)
				if (s[j] == '#')
					break;
				else if (s[j] == 'T')
					flag = true;
			cout << (flag ? "YES" : "NO") << endl;
			return 0;
		}
}
