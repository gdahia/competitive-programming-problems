#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        int mini = i;
        for (int j = i + 1; j < n; j++) {
            if (a[mini] > a[j])
                mini = j;
        }
        for (int j = mini; j > i; j--) {
            swap(a[j], a[j - 1]);
            cout << j << " " << j + 1 << endl;
        }
    }
}
