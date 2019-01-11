#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a+n);
    sort(b, b+n, greater<int>());
    for (int i = 1; i < n; i++)
        if (((i & 1) && b[i/2] > b[(i - 1)/2]) || (!(i & 1) && a[i/2] < a[(i - 1)/2])) {
            cout << "Impossible" << endl;
            return 0;
        }
    for (int i = 0; i < n; i++)
        cout << ((i & 1) ? b[i/2] : a[i/2]) << " ";
    cout << endl;
}
