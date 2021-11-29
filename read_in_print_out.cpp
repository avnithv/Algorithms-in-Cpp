#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<char> vc;

#define FOR(i, a, b) for(int i = a; i < b; i++)
#define PSH push_back
#define F first
#define S second

vc read_vc() {
  vc x;
  char c;
  while (cin.get(c) && c != '\n') x.PSH(c);
  return x;
}

vc read_vc(int n) {
  vc x;
  char c;
  FOR(i, 0, n) {cin.get(c); x.PSH(c);}
  return x;
}

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

vector<string> split(string inp, string lim) {
  vector<string> s;
  int a = inp.find(lim);
  while (a != -1) {
    s.push_back(inp.substr(0, a));
    inp = inp.substr(a + lim.size(), inp.size());
    a = inp.find(lim);
  }
  s.push_back(inp);
  return s;
}

int main(void) {
}