#include <bits/stdc++.h>
using namespace std;

int main() {
    long long h1, h2, a, b;
    cin >> h1 >> h2 >> a >> b;
    h1 += 8*a;
    if (h1 >= h2) {
        cout << 0 << endl;
        return 0;
    }
    if (b >= a) {
        cout << -1 << endl;
        return 0;
    }
    for (long long ans = 0;; ans++) {
        if (h1 >= h2) {
            cout << ans << endl;
            return 0;
        }
        h1 += 12*a - 12*b;
    }
}
