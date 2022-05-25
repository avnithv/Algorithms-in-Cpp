#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; i++)


const double PI  =3.1415926535;

void solve(int n) {
  long long r;
  int a, b;
  cin >> r >> a >> b;
  long long int f = 0;
  while (r > 0) {
    f = f + (r * r);
    cout << r << endl;
    r = r * a;
    cout << r << endl;
    f = f + (r * r);
    r = r / b;
    cout << f << endl;
  } 
  cout << f << endl;
  long double z = f * PI;
  cout << "Case #" << n << ": " << z  << endl;
}

int main() {
  int t;
  cin >> t;
  cout << setprecision(25);
  FOR(i, 0, t) solve(i + 1);
  return 0;
}