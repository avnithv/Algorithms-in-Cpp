#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef queue<int> qi;
typedef stack<int> si;
typedef priority_queue<int> pqi;
typedef priority_queue<int,vector<int>,greater<int>> pqmi;

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



void solve(int n) {
  int N, D, M;
  ll C;
  cin >> N >> D >> C >> M;
  string s;
  cin >> s;
  int last = -1;
  REV(i, 0, N) {if (s[i] == 'D') {last = i; break;}}
  FOR(i, 0, last + 1)  {
    if (D < 0 || C < 0) break;
    if (s[i] == 'D') {D--; C+=M;}
    else C--;
  } 
  string ans;
  if (D < 0 || C < 0) ans = "NO";
  else ans = "YES";
  cout << "Case #" << n << ": " << ans << "\n";
}

int main(void) {
  int t;
  cin >> t;
  FOR(i, 1, t + 1) solve(i);
  return 0;
}