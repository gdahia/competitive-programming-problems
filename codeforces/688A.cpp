#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    int ans = 0, streak = 0;
    for (int i = 0; i < d; i++) {
        string s;
        cin >> s;
        bool flag = true;
        for (char c : s)
            if (c == '0') {
                streak++;
                flag = false;
                break;
            }
        if (flag)
            streak = 0;
        ans = max(ans, streak);
    }
    ans = max(ans, streak);
    std::cout << ans << std::endl;
}
