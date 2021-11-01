#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

#define FOR(i, a, b) for(int i = a; i < b; i++)
#define REV(i, a, b) for(int i = b - 1; i >= a; i--)
#define PSH push_back
#define POP pop_back
#define MP(a, b) make_pair(a, b)
#define F first
#define S second

vvi prefix_sum(int r, int c) {
  vvi sums;
  vi first_row;
  FOR(i, 0, c + 1) first_row.PSH(0);
  sums.PSH(first_row);

  FOR(i, 1, r + 1) {
    vi row;
    row.PSH(0);
    FOR(j, 1, c + 1) { 
      int x;
      cin >> x;
      row.PSH(x + row[j - 1] + sums[i - 1][j] - sums[i - 1][j - 1]);
    }
    sums.PSH(row);
  }
  return sums;
}

int find_sum(vvi sums, pii a, pii b) {
  return sums[b.F][b.S] - sums[a.F][b.S] - sums[b.F][a.S] + sums[a.S][a.S];
}

int main(void) {
  int r, c;
  cin >> r >> c;
  cout << "\n";
  vvi sums = prefix_sum(r, c);
  
  FOR(i, 0, r + 1) {
    FOR(j, 0, c + 1) {
      cout << sums[i][j] << "\t";
    }
    cout << "\n";
  }
  
  return 0;
}