#include <bits/stdc++.h>
using namespace std;

int allZeroes(const string & s) {
    int notzeroes = 0;
    for (const auto & i : s)
        if (i != '0' && (i != '1' || ++notzeroes > 1)) return -1;
    return notzeroes;
}

int main() {
    int n;
    cin >> n;
    string h = "1", s;
    int zerocount = 0;
    while (n--) {
        cin >> s;
        int v = allZeroes(s);
        if (v > 0)
            zerocount += s.length() - 1;
        else if (v < 0)
            h = s;
        else {
            cout<<0<<endl;
            return 0;
        }
    }
    cout << h;
    while (zerocount--)
        cout << 0;
    cout<<endl;
    return 0;
}