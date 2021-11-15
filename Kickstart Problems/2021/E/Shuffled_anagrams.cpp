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
  FOR(i, 0, ss) {
    cout << s[i];
  }
  cout << "\n";
}

vpci convert(string s){
  int ss = s.length();
  vpci x;
  FOR(i, 0, ss) x.PSH(MP(s[i], i));
  return x;
}

bool check(vpci x) {
  int arr[26] = {0};
  int xs = x.size();
  FOR(i, 0, xs) {
    arr[x[i].F - 97] = arr[x[i].F - 97] + 1;
  }
  FOR(i, 0, 26) {
    if (arr[i] > xs/2) return false;
  }
  return true;
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
  vpci str = read();
  sort(str.begin(), str.end());
  if (!check(str)) {
    cout << "Case #" << n << ": IMPOSSIBLE\n";
    return;
  }
  int i = str.size();
  vpci sorted(str.begin() + i/2, str.end());
  sorted.insert(sorted.end(), str.begin(), str.begin() + i/2);
  vc fs(i);

  FOR(j, 0, i) {
    fs[str[j].S] = sorted[j].F;
  }

  cout << "Case #" << n << ": ";
  print(fs);
}

int main(void) {
  int t;
  cin >> t;
  FOR(i, 1, t + 1) solve(i);
  return 0;
}