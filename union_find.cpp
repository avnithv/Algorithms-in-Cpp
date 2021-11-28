#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

typedef vector<int> vi;

#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FE(x, s) for(auto x : s)
#define PSH push_back
#define MP(a, b) make_pair(a, b)
#define F first
#define S second
#define endl "\n"

struct vl {int ptr; int sz;};
typedef vector<vl> vvl;
typedef pair<int, vvl> pivv;

pivv find(int x, vvl s) {
  vi path;
  while(s[x].ptr >= 0) {
    path.PSH(x);
    x = s[x].ptr;
  }
  FE(val, path) {
    s[val].ptr = x;
  }
  return MP(x, s);
}

pivv union_find(int x, int y, vvl s) {
  pivv xa = find(x, s);
  s = xa.S;
  int xh = xa.F;
  pivv ya = find(y, s);
  s = ya.S;
  int yh = ya.F;

  int name;
  if (s[xh].sz >= s[yh].sz) {
    name = s[xh].ptr;
    s[yh].ptr = xh;
  } else {
    name = s[yh].ptr;
    s[xh].ptr = yh;
  }
  return MP(name, s);
}

void print(vvl x) {
  FE(val, x) {
    cout << val.ptr << " ";
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  vvl dsu;
  
  FOR(i, 0, n) {
    dsu.PSH({-i-1, 1});
  }
  
  print(dsu);

  while (true) {
    char q;
    cin >> q;
    if (q == 'f') {
      int x;
      cin >> x;
      pivv z = find(x, dsu);
      dsu = z.S;
      cout << dsu[z.F].ptr * -1 << endl;
      print(dsu);
    } else if (q == 'u') {
      int x, y;
      cin >> x >> y;
      pivv z = union_find(x, y, dsu);
      dsu = z.S;
      cout << z.F << endl;
      print(dsu);
    } else {
      break;
    }
  }
  return 0;
}