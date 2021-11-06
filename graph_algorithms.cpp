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

struct ed {int s; int e; int w;};
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

void print(vi x) {
  int xs = x.size();
  FOR(i, 0, xs) {
    cout << x[i] + 1 << " ";
  }
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
  visited[s] = true;
  FE(x, matrix[s].adjw) {
    if (visited[x.S]) continue;
    dfs(matrix, x.S, visited);
  }
}

int isLeft(bool vis[], int n) {
    FOR(i, 0, n) if (!vis[i]) return i;
    return -1;
}

int components(vn matrix) {
  int nn = matrix.size();
  bool visited[nn]; FOR(i, 0, nn) visited[i] = false;
  int n = 0; int s = -1;
  while (n != -1) {
    s++;
    dfs(matrix, n, visited);
    n = isLeft(visited, nn);
  } 
  return s;
}

vi dijkstra(vn matrix, int s, bool visited[], int dist[],vi past) {
  pqmii w;
  w.push(MP(0, s));
    
  while(!w.empty()) {
    pii x = w.top();
    w.pop();
    if(visited[x.S]) continue;
    visited[x.S] = true;

    cout << x.S << "\n";
      
    FE(y, matrix[x.S].adjw) {
      if (dist[x.S] + y.F < dist[y.S]) {
        dist[y.S] = dist[x.S] + y.F; 
        past[y.S] = x.S; 
        w.push(MP(dist[y.S], y.S));
      }
    }
  }
    return past;
}

int main() {
  int nn, ne;
  cin >> nn >> ne;
  vn matrix = makeAdjMat(nn, ne, false, false);
  cout << components(matrix);

  int n, p;
  cin >> n >> p;
  vn matrix2 = makeAdjMat(n, p);
  bool visited[n];
  int dist[n];
  FOR(i, 0, n) {
    visited[i] = false;
    if (i == 0) dist[i] = 0;
    else dist[i] = 500;
  }
  vi past(n, -1);
  past = dijkstra(matrix2, 0, visited, dist, past);
  print(past);
  return 0;
}
