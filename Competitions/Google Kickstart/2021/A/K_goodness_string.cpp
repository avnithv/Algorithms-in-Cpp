#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FE(x, s) for(auto x : s)
#define REV(i, a, b) for(int i = b - 1; i >= a; i--)
#define PSH push_back
#define POP pop_back
#define MP(a, b) make_pair(a, b)
#define F first
#define S second

void solve(int T) {
  int N, K;
  cin >> N >> K;
  
  string S;
  S.resize(N);
  cin >> S;

  int G = 0;
  FOR(i, 0, N/2) {
    if (S[i] != S[N - i - 1]) G++;
  }

  int ans = abs(K - G);
  cout << "Case #" << T << ": " << ans << "\n";
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  FOR(i, 1, T + 1) solve(i);
  return 0;
}