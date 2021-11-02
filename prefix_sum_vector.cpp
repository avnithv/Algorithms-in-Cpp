#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

typedef vector<int> vi;

#define FOR(i, a, b) for(int i = a; i < b; i++)
#define PSH push_back

vi prefix_sum(int n) {
  vi sums;
  sums.PSH(0);
  FOR(i, 1, n + 1) {
    int x;
    cin >> x;
    sums.PSH(x + sums[i - 1]);
  }
  return sums;
}

int find_sum(vi sums, int a, int b) {
  return sums[b] - sums[a];
}

int main(void) {
  int n;
  cin >> n;
  vi sums = prefix_sum(n);
  FOR(i, 0, n + 1) cout << sums[i] << " ";
  return 0;
}