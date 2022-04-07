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
string useless;


void solve(int po) {
  string n, ans = "";
  getline(cin, n);
  int sum = 0;
  FOR(i, 0, n.length()) {
    int z = n[i] - '0';
    sum += z;
  }

  int rem = (9 - sum % 9) % 9;
  bool placed = false;
  if (rem == 0) placed = true;
  FOR(j, 0, n.length()) {
    if (j == 1 && rem == 0) ans += to_string(rem);
    if (!placed && rem < n[j] - '0') {
      ans += to_string(rem);
      placed = true;
    }
    ans += n[j];
  }
  if ((rem == 0 && n.length() == 1) || !placed) ans += to_string(rem);
  cout << "Case #" << po << ": " << ans << endl;
}

int main() {
  int t;
  cin >> t;
  getline(cin, useless);
  FOR(i, 0, t) solve(i + 1);
  return 0;
}