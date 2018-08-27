#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

bool subpalindrome(const string& s, const int l, const int r) {
  for (int i = 0; i <= r - l; i++)
    if (s[l + i] != s[r - i]) return false;

  return true;
}

void solve(const int n, const int t) {
  string s;
  cin >> s;

  vector<int> vis(n + 1, 0);
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    const int front = q.front();
    q.pop();

    for (int i = n - 1; i >= front; i--)
      if (!vis[i + 1] && subpalindrome(s, front, i)) {
        vis[i + 1] = vis[front] + 1;
        q.push(i + 1);
      }
  }

  cout << "Teste " << t << endl;
  cout << vis[n] << endl;
  cout << endl;
}

int main() {
  int n, t = 1;
  while (cin >> n, n) solve(n, t++);
}
