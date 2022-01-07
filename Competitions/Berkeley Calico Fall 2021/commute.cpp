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

int split(int n) {
  vi x;
  char c;
  int min_num = -1;
  int count = 0;
  FOR(i, 0, n) {
    string z = "";
    cin.get(c);
    while(c != ',' && c != '\n') {
      if (48 <= c && c <= 57) z += c;
      cin.get(c);
    }
    int num = stoi(z);
    if (min_num < 0 || num < min_num) {
      min_num = num;
      count++;
    }
  }
  return count;
}

void solve() {
  int n;
  cin >> n;
  int ans = split(n);
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  FOR(i, 0, t) solve();
  return 0;
}