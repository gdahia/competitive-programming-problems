#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    cout << s;
    for (auto c = s.rbegin(); c != s.rend(); c++)
        cout << *c;
    cout << endl;
}
