/*
  Used for 2D Range Sum Queries
  Preprocessing: O(N^2); Runtime: O(1)
  
  Finds the sum of a rectangle in the matrix with 
  corners at indexes (a, b) and (c, d), both inclusive
  
  0 <= a <= c; 0 <= b <= d;
*/

#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

#define FOR(i, a, b) for(int i = a; i < b; i++)
#define PSH push_back
#define MP(a, b) make_pair(a, b)
#define F first
#define S second
#define endl "\n"

struct psum2D {
  vvi sums;

  // Constructs prefix sum matrix from input
  void init(int r, int c) {
    sums = vvi(r + 1, vi(c + 1, 0)); 
    FOR(i, 1, r + 1) {
      vi row(c + 1, 0);   
      FOR(j, 1, c + 1) { 
        int x; cin >> x; // Or take from existing matrix
        row[j] = x + row[j - 1] + sums[i - 1][j] - sums[i - 1][j - 1];
      }
      sums[i] = row;
    }
  }

  // Returns the sum of the rectangle made by index pairs a (inclusive) and b (inclusive)
  int sum(pii a, pii b) {
    return sums[b.F + 1][b.S + 1] - sums[a.F][b.S + 1] - sums[b.F + 1][a.S] + sums[a.F][a.S];
  }
};


int main(void) {
  // Input number of rows and columns and the matrix
  int r, c; cin >> r >> c;
  psum2D s; s.init(r, c);

  // Print the prefix sum matrix
  FOR(i, 0, r + 1) {
    FOR(j, 0, c + 1) {
      cout << s.sums[i][j] << " ";
    }
    cout << endl;
  }

  // Find the sum of rectangle from (a, b) to (c, d)
  try {
    int a, b, c, d; cin >> a >> b >> c >> d;
    while (a >= 0 && c >= a && b >= 0 && d >= b) {
      cout << s.sum(MP(a, b), MP(c, d)) << endl;
      cin >> a >> b >> c >> d;
    }
  } catch (exception e) {}
  return 0;
}
