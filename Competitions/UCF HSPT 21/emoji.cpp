#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  char f;
  cin >> f;
  for (int i = 0; i < cases; i++) {
    string s;
    getline(cin, s);

    bool ems[26] = {0};
    bool flg = false;
    for (char c : s) {
      if (ems[c - 65]) {flg = true; break;}
      ems[c - 65] = 1;
    }
    if (flg) cout << "Nope\n";
    else cout << "Emote away!\n";
  }
  return 0;
}