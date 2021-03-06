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

bool isPalindrome(int x) {
  if (x <= 1) return false;
  if (x < 10) return true;
  string s = to_string(x);
  for (int i = 0; i < s.size() / 2; i++) {
    if (s[i] != s[s.size() - i - 1]) return false;
  }
  return true;
}

void solve(int n) {
  long long a;
  cin >> a;
  int s = 1 + isPalindrome(a);
  for (int i = 2; i <= sqrt(a); i++) {
    if (a % i == 0) {
      s += isPalindrome(i);
      if (a / i != i) s += isPalindrome(a / i);
    }
  }
  cout << "Case #" << n << ": " << s << endl;
}

int main() {
  int t;
  cin >> t;
  FOR(i, 0, t) solve(i + 1);
  return 0;
}