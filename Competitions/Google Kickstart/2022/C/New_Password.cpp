#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;


#define FOR(i, a, b) for(int i = a; i < b; i++)
#define endl "\n"

int main() {
  int t; cin >> t;
  FOR(o, 0, t) 
  {
    int n; string s; cin >> n >> s;
    bool upp = false, low = false, dig = false, spe = false;
    string sp = "#@&*";
    FOR(i, 0, n) {
      if (s[i] - 'A' >= 0 && s[i] - 'A' <= 25) upp = true;
      if (s[i] - 'a' >= 0 && s[i] - 'a' <= 25) low = true;
      if (s[i] - '0' >= 0 && s[i] - '0' <= 9) dig = true;
      if (sp.find(s[i]) != string::npos) spe = true;
    }
    if (!upp) s+= "A";
    if (!low) s+= "a";
    if (!dig) s+= "1";
    if (!spe) s+= "#";
    FOR(k, s.length(), 7) {
      s += "1";
    }
    cout << "Case #" << o + 1 << ": " << s << endl;
  }
  return 0;
}