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
  for (const char c : b)
    for (const int index : a_char_pos[c - 'a']) {
      seq.push_back(index);
      // cout << index << " ";
    }
  // cout << endl;

  const int len = seq.size();
  int lis[len];
  int ans = 0;
  for (int i = 0; i < len; i++) {
    lis[i] = 1;
    for (int j = 0; j < i; j++)
      if (seq[i] > seq[j]) lis[i] = max(lis[i], lis[j] + 1);
    ans = max(ans, lis[i]);
  }
  cout << ans << endl;

  // const int len = seq.size();
  // vector<int> aux;
  // aux.push_back(-1);
  // for (int i = 0; i < len; i++) {
  // int lis = 1;
  // auto lb = lower_bound(aux.begin(), aux.end(), seq[i] - 1);
  // if (lb != aux.end()) lis = lb - aux.begin() + 1;
  // cout << lis << endl;
  // if (lis == aux.size())
  // aux.push_back(seq[i]);
  // else
  // aux[lis] = min(aux[lis], seq[i]);
  //}

  // cout << aux.size() << endl;
}
