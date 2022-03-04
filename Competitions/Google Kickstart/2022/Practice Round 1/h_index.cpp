#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef queue<int> qi;
typedef stack<int> si;
typedef priority_queue<int> pqi;
typedef priority_queue<int,vector<int>,greater<int>> pqmi;
typedef vector<char> vc;
typedef vector<pair<char, int>> vpci;

struct ed {int s; int e; int w;};
typedef vector<ed> ve;

struct nd {int i; vpii adjw;};
typedef vector<nd> vn;
typedef priority_queue<pii> pqii;
typedef priority_queue<pii,vector<pii>,greater<pii>> pqmii;

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
#define endl "\n"

void print(vi x) {
  int xs = x.size();
  FOR(i, 0, xs) {
    cout << x[i] << " ";
  }
  cout << endl;
}

void solve(int q) {
  int n, z = 0, y = 0; 
  cin >> n;
  vi x(n + 1, 0);
  vi r;
  FOR(i, 0, n) {
    int c;
    cin >> c;
    if (c > n) c = n;
    if (c <= z) {
      r.PSH(z);
      continue;
    }
    x[c]++;
    if (++y > z) {
      z++;
      y -= x[z];
    }
    r.PSH(z);
  }
  cout << "Case #" << q << ": ";
  print(r);
}

int main() {
  int t;
  cin >> t;
  FOR(i, 0, t) solve(i + 1);
  return 0;
}