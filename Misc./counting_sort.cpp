/* 
  Sorting algorithm
  Runtime: O(N) 
  All values in the vector must be in the range
  0 <= x <= n
*/


#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;
 
typedef vector<int> vi;

#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FE(x, s) for(auto x : s)
#define PSH push_back

// Does counting sort on vector x with n bins
vi count_sort(vi x, int n) {
  vi count(n + 1, 0);
  vi sorted;
  FE(v, x) count[v]++;
  FOR(i, 0, n + 1) {
    FOR(j, 0, count[i]) {
      sorted.PSH(i);
    }
  }
  return sorted;
}

int main() {
  // Input the number of bins for counting sort and the vector
  vi x; int n; cin >> n;
  while (true) {
    int i; cin >> i;
    if (i < 0) break; if (i > n) i = n;
    x.PSH(i);
  }

  // Before sort
  FOR(i, 0, x.size()) cout << x[i] << " ";
  cout << endl;
  
  vi y = count_sort(x, n);
  // After sort
  FOR(i, 0, y.size()) cout << y[i] << " ";
  cout << endl;
  return 0;
}