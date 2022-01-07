#include <bits/stdc++.h>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

#define f first
#define s second

double dist(vpii x, vpii curr) {
  int xs = x.size(); 
  double dis = 0.0;
  for (int i = 0; i < xs; i++) {
    dis += hypot(x[i].f - curr[i].f, x[i].s - curr[i].s);
  }
  return dis;
}

double min_perm(vpii v, vpii x, vpii curr, vector<bool> vis) {
  if (curr.size() == v.size()) {
    return dist(x, curr);
  }
  else {
    double mn = -1.0;
    for (int i = 0; i < v.size(); i++) {
      if (vis[i]) continue;
      vis[i] = true;
      curr.push_back(v[i]);
      
      double ans = min_perm(v, x, curr, vis);
      if (mn == -1.0) mn = ans;
      else if (ans != -1.0) mn = min(mn, ans);
      
      curr.pop_back();
      vis[i] = false;
    }
    return mn;
  }
}

int main() {
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    int bananas;
    cin >> bananas;
    vpii v;
    vpii s;
    for (int j = 0; j < bananas; j++) {
      int a, b;
      cin >> a >> b;
      v.push_back(make_pair(a, b));
    }
    for (int k = 0; k < bananas; k++) {
      int a, b;
      cin >> a >> b;
      s.push_back(make_pair(a, b));
    }

    vector<bool> vis(bananas, false);
    vpii curr;
    double mn = min_perm(v,s,curr,vis);
    cout << setprecision(10) << mn << "\n";
  }
  return 0;
}