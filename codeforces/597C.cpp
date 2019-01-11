#include <bits/stdc++.h>

using namespace std;

long long query_tree(int n, long long * tree) {
    long long ret = 0;
    while (n > 0) {
        ret += tree[n];
        n -= (n & -n);
    }
    return ret;
}

void update_tree(int n, long long * tree, const int & max_val, const long long & upd) {
    while (n <= max_val) {
        tree[n] += upd;
        n += (n & -n);
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int max_val = 0, a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }
    long long tree[k + 2][n + 1];
    memset(tree, 0, sizeof(tree));
    for (int i = 0; i < n; i++) {
        update_tree(a[i], tree[1], n, 1);
        for (int j = 1; j <= k; j++)
            update_tree(a[i], tree[j + 1], n, query_tree(a[i] - 1, tree[j]));
    }
    cout << query_tree(n, tree[k + 1]) << endl;
}