/*
  Used for Range Sum Queries
  Preprocessing: O(N); Runtime: O(1)
  
  Finds the sum of a range in the array 
  from indexes a to b, both inclusive.
  
  0 <= a <= b;
*/


#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

typedef vector<int> vi;

#define FOR(i, a, b) for(int i = a; i < b; i++)
#define PSH push_back
#define endl "\n"


struct psum {
  vi sums;
  
  // Constructs prefix sum vector from input
  void init(int n) {
    sums = vi(n + 1, 0);
    FOR(i, 1, n + 1) {
      int x; cin >> x;
      sums[i] = x + sums[i - 1];
    }
  }

  // Calculates the sum from index a (inclusive) to b (inclusive)
  // a <= b
  int sum(int a, int b) {
    return sums[b + 1] - sums[a];
  }
};

int main(void) {
  // Input the vector size and the vector
  int n; cin >> n;
  psum s; s.init(n);

  // Print the prefix sum vector
  FOR(i, 0, n + 1) cout << s.sums[i] << " ";
  cout << endl;
  
  // Prints sum of range [a, b]
  try {
    int a, b; cin >> a >> b;
    while (a >= 0 && b >= a) {
      cout << s.sum(a, b) << endl;
      cin >> a >> b;
    }
  } catch (exception e) {}
  return 0;
}