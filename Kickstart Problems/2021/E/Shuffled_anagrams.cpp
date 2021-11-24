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

void print(vc s) {
  int ss = s.size();
  FOR(i, 0, ss) cout << s[i];
  cout << "\n";
}

void print(vpci s) {
  int ss = s.size();
  FOR(i, 0, ss) cout << s[i].F << s[i].S << "\n";
  cout << "\n";
}

vc sort(vpci x, int n) {
  vector<vpci> count(n);
  int xs = x.size();
  vpci str;
  vc fs(xs, '0');
  FE(v, x) count[v.F - 97].PSH(v);
  FE(i, count) {
    int is = i.size();
    if (is > xs/2) return fs;
    FE(j, i) str.PSH(j);
  }
  FOR(x, 0, xs) {
    fs[str[x].S] = str[(x+xs/2) % xs].F;
  }
  return fs;
}

vpci read() {
  vpci x;
  char c;
  cin >> c;
  x.PSH(MP(c, 0));
  int i = 1;
  while (cin.get(c)) {
    if (c < 97 || c > 122) break;
    x.PSH(MP(c, i++));
  }
  return x;
}

void solve(int n) {
  vpci x = read();
  vc ans = sort(x, 26);
  if (ans[0] == '0') {
    cout << "Case #" << n << ": IMPOSSIBLE\n";
    return;
  }
  cout << "Case #" << n << ": ";
  print(ans);
}

int main(void) {
  int t;
  cin >> t;
  FOR(i, 1, t + 1) solve(i);
  return 0;
}