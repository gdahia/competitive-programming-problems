#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, v[4];
    cin >> n >> v[1] >> v[2] >> v[3];
    long long ans[4];
    ans[0] = 0;
    ans[3] = min({v[1], 3*v[3], v[2] + v[3]});
    ans[2] = min({v[2], 2*v[1], 2*v[3]});
    ans[1] = min({v[2] + v[1], ans[2] + v[1], 3*v[1], v[3]});
    cout << ans[(n % 4)] << endl;
}
