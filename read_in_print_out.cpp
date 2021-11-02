#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

#define FOR(i, a, b) for(int i = a; i < b; i++)
#define PSH push_back
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

void print(vpii x) {
  int xs = x.size();
  FOR(i, 0, xs) {
    cout << x[i].F << " " << x[i].S << "\n";
  }
}

int main(void) {
}