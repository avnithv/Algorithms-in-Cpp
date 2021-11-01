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

vi read_vi(int n) {
  vi x;
  FOR(i, 0, n) {
    int y;
    cin >> y;
    x.PSH(y);
  }
  return x;
}

vvi read_vvi(int r, int c) {
  vvi x;
  FOR(i, 0, r) {
    vi row;
    FOR(j, 0, c) {
      int y;
      cin >> y;
      row.PSH(y);
    }
    x.PSH(row);
  }
  return x;
}

void print(vi x) {
  int xs = x.size();
  FOR(i, 0, xs) {
    cout << x[i] << " ";
  }
  cout << "\n";
}

void print(vvi x) {
  int xs = x.size();
  FOR(i, 0, xs) {
    int ys = x[i].size();
    FOR(j, 0, ys) {
      cout << x[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

int main(void) {
}