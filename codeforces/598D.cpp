#include <bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a), b, sizeof(a))

using namespace std;

void dfs(const string * mapa, int x, int y, int & ans, const int & n, const int & m, const int & idx, int ** vis) {
    if (x >= 0 && y >= 0 && x < n && y < m) {
        if (mapa[x][y] == '*') {
            ans++;
        }
        else if (!vis[x][y]) {
            // cout << "dfs(" << x + 1 << "," << y + 1 << ")" << endl;
            vis[x][y] = idx;
            dfs(mapa, x + 1, y, ans, n, m, idx, vis);
            dfs(mapa, x - 1, y, ans, n, m, idx, vis);
            dfs(mapa, x, y + 1, ans, n, m, idx, vis);
            dfs(mapa, x, y - 1, ans, n, m, idx, vis);
        }
    }
}

int main() {
    int n, m, k, x, y, ans, **vis;
    scanf("%d%d%d", &n, &m, &k);
    string mapa[n];
    vis = (int **) malloc(n*sizeof(int *));
    for (int i = 0; i < n; i++) {
        cin >> mapa[i];
        vis[i] = (int *) malloc(m*sizeof(int ));
        for (int j = 0; j < m; j++)
            vis[i][j] = 0;
    }
    map <int, int> memo;
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &x, &y);
        ans = 0;
        x--, y--;
        if (!vis[x][y]) {
            dfs(mapa, x, y, ans, n, m, i + 1, vis);
            memo[i+1] = ans;
        }
        else
            ans = memo[vis[x][y]];
        printf("%d\n", ans);
    }
    return 0;
}