#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <complex>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef queue

<int> qi;
typedef stack<int> si;
typedef priority_queue<int> pqi;
typedef priority_queue<int,vector<int>,greater<int>> pqmi;

struct ed {int s; int e; int w;};
typedef vector<ed> ve;

struct nd {int i; vpii adjw;};
typedef vector<nd> vn;
typedef priority_queue<pii> pqii;
typedef priority_queue<pii,vector<pii>,greater<pii>> pqmii;

typedef complex<int> P;
typedef vector<P> vp;

#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FE(x, s) for(auto x : s)
#define REV(i, a, b) for(int i = b - 1; i >= a; i--)
#define PSH push_back
#define POP pop_back
#define MP(a, b) make_pair(a, b)
#define F first
#define S second
#define X real()
#define Y imag()

int dist(P p1, P p2) {
  return abs(p2 - p1);
}

P mv(P p1, P p2) {
  return {p2.X - p1.X, p2.Y - p1.Y};
}

double cross(P v1, P v2) {
  return (conj(v1) * v2).Y;
}

double triangle_area(P p1, P p2, P p3) {
  return cross(mv(p1, p2), mv(p1, p3)) /2.;
}

double shoelace(vp ps) {
  int xs = ps.size();
  double area = 0;
  FOR(i, 0, xs) {
    int x = (i + 1) % xs;
    area += 1;
  }
  return abs(area) / 2;
}