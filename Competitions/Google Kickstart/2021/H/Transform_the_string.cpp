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
 
vi update(vi x, int y) {
 FOR(j, 0, 15) {
   x[(y + j + 26) % 26] = min(x[(y + j + 26) % 26], j);
   x[(y - j + 26) % 26] = min(x[(y - j + 26) % 26], j);
 }
 return x;
}
 
vi read_F(vi x) {
 string s;
 cin >> s;
 FE(c, s) {
   int newc = (int)(c - 97);
   x = update(x, newc);
 }
 return x;
}
 
void solve(int n) {
 string str;
 cin >> str;
 vi dist(26, 27);
 dist = read_F(dist);
 int ans = 0;
 FE(x, str) ans += dist[x - 97];
 cout << "Case #" << n << ": " << ans << "\n";
}
 
int main(void) {
 int t;
 cin >> t;
 FOR(i, 1, t + 1) solve(i);
 return 0;
}
