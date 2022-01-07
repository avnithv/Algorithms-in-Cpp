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

void print(vi x) {
  int xs = x.size();
  FOR(i, 0, xs) {
    cout << x[i] << " ";
  }
  cout << "\n";
}

void solve(int n) {
  int N, l;
  string S;
  char last;
  cin >> N >> S;
  
  last = S[0];
  l = 1;
  vi ans;
  ans.PSH(1);

  FOR(i, 1, N) {
    if (S[i] > last) ans.PSH(++l);
    else {ans.PSH(1); l = 1;}
    last = S[i];
  }

  cout << "Case #" << n << ": ";
  print(ans);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  FOR(i, 1, t + 1) solve(i);
  return 0;
}