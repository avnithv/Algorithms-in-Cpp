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

typedef unordered_set<int> ui;
typedef pair<bool, ui> pbui;

bool DEBG = true;

void print(string s) {
  if (DEBG) cout << s << endl;
}

void print(vi x) {
  if (DEBG) {
    int xs = x.size();
    FOR(i, 0, xs) {
      cout << x[i] << " ";
    }
    cout << "\n";
  }
}

void print(vvi x) {
  if (DEBG) {
    int xs = x.size();
    FOR(i, 0, xs) {
      int ys = x[i].size();
      FOR (k, 0, i) {
        cout << " ";
      }
      FOR(j, 0, ys) {
        cout << x[i][j] + 1 << " ";
      }
      cout << "\n";
    }
    cout << "\n";
  }
}

int N;
vvi board;
vpii mve = {
  MP(0, -1),
  MP(-1, 0),
  MP(-1, 1),
  MP(0, 1),
  MP(1, 0),
  MP(1, -1)
};
bool col = true;
vector<string> outcome = {
  "Nobody wins",
  "Blue wins",
  "Red wins",
  "Impossible"
};

bool isCorner(int x, int y) {
  return (x == 0 || x == N + 1) && (y == 0 || y == N + 1);
}

bool outBounds(vi in) {
  return in[0] < 0 || in[0] > N + 1 || in[1] < 0 || in[1] > N + 1;
}

vi next(vi in) {
  if (!outBounds(in) && board[in[0]][in[1]] == col) {
    in[0] += mve[in[2]].F;
    in[1] += mve[in[2]].S;
    in[2] = (in[2] + 1) % 6;
  } else {
    in[0] += mve[(in[2] + 3) % 6].F;
    in[1] += mve[(in[2] + 3) % 6].S;
    in[2] = (in[2] + 5) % 6;
  }
  return in;
}

pbui traverse(vi nx, int x, int y) {
  ui cells;
  while (!isCorner(nx[0], nx[1])) {
    print(nx);
    pii mv = mve[(nx[2] + 2) % 6];
    cells.insert((nx[0] + mv.F) * (N + 2) + (nx[1] + mv.S));
    nx = next(nx);
  }
  pii mv = mve[(nx[2] + 2) % 6];
  cells.insert((nx[0] + mv.F) * (N + 2) + (nx[1] + mv.S));
  return MP((nx[0] == x && nx[1] == y), cells);
}

bool checkDisjoint(ui a, ui b) {
  FE(x, a) if (b.count(x) > 0) return false;
  return true;
}

int solve() {
  cin >> N;
  vvi boar(N + 2, vi(N + 2, -1));
  FOR (i, 0, N + 2) {
    boar[i][0] = 1;
    boar[i][N + 1] = 1;
    boar[0][i] = 0;
    boar[N + 1][i] = 0;
  }

  int B = 0, R = 0;
  FOR (a, 1, N + 1) {
    FOR(b, 1, N + 1) {
      char ch;
      cin >> ch;
      int num = -1;
      if (ch == 'B') {
        num = 1;
        B++;
      }
      if (ch == 'R') {
        num = 0;
        R++;
      }
      boar[a][b] = num;
    }
  }
  if (abs(B - R) > 1) return 3;
  board = boar;

  print(board);
  
  col = true;
  vi in(3);
  in = {N, 1, 3};
  
  pbui a = traverse(in, N + 1, N + 1);

  print("---------------");
  in = {1, N, 0};
  
  pbui b = traverse(in, 0, 0);

  print("---------------");
  if (a.F && b.F) {
    if (R > B || checkDisjoint(a.S, b.S)) return 3;
    else return 1;
  }
  
  col = false;
  in = {1, 1, 5};

  pbui c = traverse(in, N + 1, 0);
  
  print("---------------");
  in = {N, N, 2};

  pbui d = traverse(in, 0, N + 1);
  
  print("---------------");
  if (c.F && d.F) {
    if (B > R || checkDisjoint(c.S, d.S)) return 3;
    else return 2;
  }
  return 0;
}

int main() {
  int t;
  cin >> t;
  int T = t;
  while (t --> 0) {
    string s =  outcome[solve()];
    cout << "Case #" << T - t << ": " << s << endl;
  }
  return 0;
}