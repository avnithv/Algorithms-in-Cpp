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

struct ed {int s; int e; int w;
bool operator<(ed x) {return w < x.w;}};
typedef vector<ed> ve;

struct nd {int i; vpii adjw;};
typedef vector<nd> vn;
typedef priority_queue<pii,vector<pii>,greater<pii>> pqmii;

#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FE(x, s) for(auto x : s)
#define PSH push_back
#define MP(a, b) make_pair(a, b)
#define F first
#define S second

void print(vpii x) {
  int xs = x.size();
  FOR(i, 0, xs) {
    cout << x[i].F << " " << x[i].S + 1 << "\n";
  }
}

void print(vn x) {
  int xs = x.size();
  FOR(i, 0, xs) {
    cout << x[i].i + 1 << ":\n";
    print(x[i].adjw);
  }
  cout << "\n";
}

ve makeEdgeList(int nn, int ne, bool isDirected, bool isWeighted) {
  ve edges;
  FOR(i, 0, ne) {
    int s, e;
    int w = 0;
    cin >> s >> e;
    if (isWeighted) cin >> w;
    edges.PSH({--s, --e, w});
    if (!isDirected) edges.PSH({e, s, w});
  }
  return edges;
}

vn makeAdjMat(int nn, int ne, bool isDirected, bool isWeighted) {
  vn matrix;
  FOR(i, 0, nn) matrix.PSH({i, vpii()});
  FOR(j, 0, ne) {
    int s, e;
    int w = 0;
    cin >> s >> e;
    if (isWeighted) cin >> w;
    matrix[--s].adjw.PSH(MP(w, --e));
    if (!isDirected) matrix[e].adjw.PSH(MP(w, s));
  }
  return matrix;
}

void dfs(vn matrix, int s, bool visited[]) {

  cout << s + 1 << "\n";

  visited[s] = true;
  sort(matrix[s].adjw.begin(), matrix[s].adjw.end());
  FE(x, matrix[s].adjw) {
    if (visited[x.S]) continue;
    dfs(matrix, x.S, visited);
  }
}

void bfs(vn matrix, int s, bool visited[]) {
  qi next;
  next.push(s);

  while (!next.empty()) {
    int x = next.front();
    next.pop();

    if (visited[x]) continue;
    visited[x] = true;
    
    cout << x + 1 << "\n";
    
    sort(matrix[x].adjw.begin(), matrix[x].adjw.end());
    FE(y, matrix[x].adjw) {
      next.push(y.S);
    }
  }
}

void wfs(vn matrix, int s, bool visited[]) {
  pqmii w;
  w.push(MP(0, s));

  while(!w.empty()) {
    pii x = w.top();
    w.pop();
    visited[x.S] = true;

    cout << x.S + 1 << "\n";

    FE(y, matrix[x.S].adjw) {
      if (visited[y.S]) continue;
      w.push(y);
    }
  }
}

int main(void) {
  int n, e;
  cin >> n >> e;
  vn matrix = makeAdjMat(n, e, true, true);
  
  cout << "\n";
  print(matrix);
  
  int s;
  cin >> s;
  s--;
  cout << "\n";

  bool visited[n];
  FOR(i, 0, n) visited[i] = false;
  dfs(matrix, s, visited);
  cout << "\n";

  FOR(i, 0, n) visited[i] = false;
  bfs(matrix, s, visited);
  cout << "\n";

  FOR(i, 0, n) visited[i] = false;
  wfs(matrix, s, visited);
}