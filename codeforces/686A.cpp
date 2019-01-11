#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long long n, x, dist = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        char c;
        int d;
        cin >> c >> d;
        switch (c) {
            case '+': x += d; break;
            case '-': (x >= d ? x -= d : dist++); break;
            default: std::cerr << "error" << std::endl; return 1;
        }
    }
    std::cout << x << " " << dist << std::endl;
}
