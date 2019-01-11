#include <bits/stdc++.h>
using namespace std;

int main() {
    long long k, a, b;
    cin >> k >> a >> b;
    long double ans = floorl((long double) b/k) - ceil((long double) a/k) + 1;
    if (ans < 0)
        ans = 0;
    cout << (long long) ans << endl;
}