#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  const int n = a.size();
  const int m = b.size();

  vector<int> a_char_pos[26];
  for (int i = 0; i < n; i++) a_char_pos[a[i] - 'a'].push_back(i);
  for (int i = 0; i < 26; i++)
    reverse(a_char_pos[i].begin(), a_char_pos[i].end());

  vector<int> seq;
  for (int i = 0; i < m; i++) {
    const char c = b[i];
    for (const int index : a_char_pos[c - 'a']) seq.push_back(index);
  }

  const int len = seq.size();
  vector<int> aux;
  aux.push_back(-1);
  for (int i = 0; i < len; i++) {
    int lis = 1;
    int l = 1, r = aux.size() - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (aux[m] <= seq[i])
        l = m + 1;
      else
        r = m - 1;
    }
    lis = l;
    if (lis == aux.size())
      aux.push_back(seq[i]);
    else
      aux[lis] = min(aux[lis], seq[i]);
  }

  cout << aux.size() - 1 << endl;
}
