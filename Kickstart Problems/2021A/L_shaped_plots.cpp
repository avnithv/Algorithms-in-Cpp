#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

#define FOR(i, a, b) for(int i = a; i < b; i++)
#define REV(i, a, b) for(int i = b - 1; i >= a; i--)
#define PSH push_back
#define POP pop_back
#define MP(a, b) make_pair(a, b)
#define F first
#define S second

void print(vvi x) {
/*  int xs = x.size();
  FOR(i, 0, xs) {
    int ys = x[i].size();
    FOR(j, 0, ys) {
      cout << x[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
*/}

vvi read_vvi(int r, int c) {
  vvi x;
  FOR(i, 0, r) {
    vi row;
    FOR(j, 0, c) {
      int y;
      cin >> y;
      row.PSH(y);
    }
    x.PSH(row);
  }
  return x;
}

int count(int x, int y) {
  int s1 = min(x/2, y) - 1;
  int s2 = min(x, y/2) - 1;
  if (s1 < 0) s1 = 0;
  if (s2 < 0) s2 = 0;
  return s1 + s2;
}

void solve(int n) {
  int r, c;
  cin >> r >> c;

  vvi grid = read_vvi(r, c);
  print(grid);

  vvi T(r, vi(c, 0));
  vvi L(r, vi(c, 0));
  vvi B(r, vi(c, 0));
  vvi R(r, vi(c, 0));

  FOR(a, 0, r) {
    FOR(b, 0, c) {
      if (grid[a][b] == 0) continue;
      
      if (a != 0) T[a][b] = T[a-1][b] + 1;
      else T[a][b] = 1;
      
      if (b != 0) L[a][b] = L[a][b-1] + 1;
      else L[a][b] = 1;
    }
  }

  REV(i, 0, r) {
    REV(j, 0, c) {
      if (grid[i][j] == 0) continue;
      
      if (i != r - 1) B[i][j] = B[i+1][j] + 1;
      else B[i][j] = 1;

      if (j != c - 1) R[i][j] = R[i][j+1] + 1;
      else R[i][j] = 1;
    }
  }

  print(T);
  print(L);
  print(B);
  print(R);

  int ans = 0;
  FOR(x, 0, r) {
    FOR(y, 0, c) {
      ans += count(T[x][y], L[x][y]) + count(T[x][y], R[x][y]) + count(B[x][y], L[x][y]) + count(B[x][y], R[x][y]);
    }
  }
  
  cout << "Case #" << n << ": " << ans << "\n";
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  FOR(i, 1, t + 1) solve(i);
  return 0;
}