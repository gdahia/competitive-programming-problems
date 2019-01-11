#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int p[n], last[n + 1];
    vector<int> foe[n+1];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        foe[a].push_back(b);
        foe[b].push_back(a);
    }
    long long ans = 0;
    memset(last, -1, sizeof(last));
    for (int l = 0, r = 0; l < n; l++) {
        while (r < n && last[p[r]] < l) {
            for (int i : foe[p[r]])
                last[i] = r;
            r++;
        }
        ans += r - l;
    }
    cout << ans << endl;
}
