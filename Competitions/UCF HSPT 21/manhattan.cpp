#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    if (x1 == y1 || x2 == y2) cout << "Dr. Manhattan wins again!\n";
    else cout << "Euclid is too fast!\n";
  }
  return 0;
}