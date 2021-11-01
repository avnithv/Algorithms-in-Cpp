#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

struct ed {int s; int e;};
typedef vector<ed> ve;

struct wed {ed e; int w;};
typedef vector<wed> vwe;

struct nd {int i; vi adj;};
typedef vector<nd> vn;

struct wnd {int i; vpii adjw;};
typedef vector<wnd> vwn;

#define FOR(i, a, b) for(int i = a; i < b; i++)
#define REV(i, a, b) for(int i = b - 1; i >= a; i--)
#define PSH push_back
#define POP pop_back
#define MP(a, b) make_pair(a, b)
#define F first
#define S second

ve makeEdges(int n) {
  ve edges(n);
  int s, e;
  cin >> s >> e;
  edges.PSH({s, e});
  return edges;
}

vn makeAdjMat(int n) {
  vn matrix;
  FOR(i, 0, n) matrix.PSH({i, vi(0)});
  int s, e;
  cin >> s >> e;
  matrix[s].adj.PSH(e);
  return matrix;
}