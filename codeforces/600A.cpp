#include <bits/stdc++.h>
#define pb push_back
#define ms(a, b) memset((a), b, sizeof(a))

using namespace std;

int main() {
	string s, a, b, tmp;
	a += '"';
	b += '"';
	cin >> s;
	int len = s.length(), flag = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] != ',' && s[i] != ';') {
			if (s[i] < '0' || s[i] > '9' || (tmp.length() && tmp[0] == '0'))
				flag = 1;
			tmp += s[i];
		}
		else if (flag || !tmp.length()) {
			b += tmp + ',';
			tmp = "";
			flag = 0;
		}
		else {
			a  += tmp + ',';
			tmp = "";
		}
	}
	if (flag || !tmp.length()) {
		b += tmp + '"';
		a[a.length() - 1] = '"';
	}
	else {
		a += tmp + '"';
		b[b.length() - 1] = '"';
	}
	if (a.length() <= 1)
		a = "-";
	if (b.length() <= 1)
		b = "-";
	cout << a << endl << b << endl;
	return 0;
}
