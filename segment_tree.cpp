#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

typedef vector<int> vi;

typedef priority_queue<int> pqi;

#define FOR(i, a, b) for(int i = a; i < b; i++)
#define REV(i, a, b) for(int i = b - 1; i >= a; i--)
#define PSH push_back

int l(int n) {return 2 * n + 1;}
int r(int n) {return 2 * n + 2;}
int p(int n) {return (n + 1) / 2 - 1;}

void print(vi x) {
  int xs = x.size();
  FOR(i, 0, xs) {
    cout << x[i] << " ";
  }
  cout << "\n";
}

vi make_st(vi vals) {
  int s = vals.size();
  int n = 2 * (int)pow(2, ((int)ceil(log2(s)))) - 1;
  vi st(n);

  FOR(i, n / 2, n) {
    if (i <= s + n/2) st[i] = vals[i - n/2];
    else st[i] = 0;
  }

  REV(j, 0, n/2) st[j] = st[l(j)] + st[r(j)];
  return st;
}

int get_range(vi st, int s, int e) {
  int x = 0;
  s += st.size() / 2;
  e += st.size() / 2 - 1;
  while (s <= e && s >= 0) {
    if (!(s % 2)) x += st[s++];
    if (e % 2) x += st[e--];
    s = p(s);
    e = p(e);
  }
  return x;
}

int main() {
  int n;
  cin >> n;
  vi vals;
  
  FOR(i, 0, n) {
    int x;
    cin >> x;
    vals.PSH(x);
  }

  vi st = make_st(vals);
  print(st);

  cout << get_range(st, 0, n) << "\n";

  int a, b;
  cin >> a >> b;
  cout << get_range(st, --a, b) << "\n";

  return 0;
}