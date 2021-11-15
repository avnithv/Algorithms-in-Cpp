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
 
int read_vc() {
 int y = 0, r = 0, b = 0;
 bool Y = false, R = false, B = false;
 char c;
 while (cin.get(c) && c != '\n') {
   if (c == 'Y' || c == 'O' || c == 'G' || c == 'A') {
     Y = true;
   } else {if (Y) y++; Y = false;}
   if (c == 'B' || c == 'P' || c == 'G' || c == 'A') {
     B = true;
   } else {if (B) b++; B = false;}
   if (c == 'R' || c == 'O' || c == 'P' || c == 'A') {
     R = true;
   } else {if (R) r++; R = false;}
 }
 return y + b + r + Y + B + R;
}
 
void solve(int n) {
 int N;
 cin >> N;
 char c;
 cin.get(c);
 int ans = read_vc();
 cout << "Case #" << n << ": " << ans << "\n";
}
 
int main(void) {
 int t;
 cin >> t;
 FOR(i, 1, t + 1) solve(i);
 return 0;
}