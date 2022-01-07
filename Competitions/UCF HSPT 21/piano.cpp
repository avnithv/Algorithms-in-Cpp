#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  char f;
  cin.get(f);
  for (int i = 0; i < cases; i++) {
    string s;
    getline(cin, s);
    for (char c : s) {
      if (65 > c || c > 71) break;
      cout << "L";
    }
    cout << "\n";
  }
  return 0;
}