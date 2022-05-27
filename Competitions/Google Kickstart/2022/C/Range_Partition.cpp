#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

typedef vector<int> vi;

#define FOR(i, a, b) for(int i = a; i < b; i++)
#define endl "\n"

int main() {
  int t; cin >> t;
  FOR(cs, 1, t + 1) 
  {
    int N, X, Y; cin >> N >> X >> Y;
    if ((N * (N + 1) / 2) % (X + Y) != 0) { 
      cout << "Case #" << cs << ": IMPOSSIBLE" << endl;
      continue;
    }
    int z = ((N * (N + 1) / 2) / (X + Y)) * X;
    vi ls;
    while (z != 0) {
      if (z < N) {
        ls.push_back(z);
        z = 0;
      } else {
        ls.push_back(N);
        z -= N;
        N -= 1;
      }
    }
    cout << "Case #" << cs << ": POSSIBLE" << endl;
    cout << ls.size() << endl;
    FOR(i, 0, ls.size()) {
      cout << ls[i];
      if (i != ls.size() - 1) cout << " ";
    }
    cout << endl;
  }
  return 0;
}