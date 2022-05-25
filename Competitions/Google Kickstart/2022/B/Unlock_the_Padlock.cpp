#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

// Definitions
#define DEBUG(a) dbg.DEBG = (a);
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define F first
#define S second
#define endl "\n"


// Typedefs
typedef vector<long long> vi;
typedef vector<vector<long long>> vvi;
typedef vector<vector<vector<long long>>> vvvi;

class Debug {
  public:
    bool DEBG = false;
    
    void print(string s) {
      if (Debug::DEBG) cout << s << endl;
    }
    
    void print(int s) {
      if (Debug::DEBG) cout << s << endl;
    }

    void print(bool s) {
      if (Debug::DEBG) cout << s << endl;
    }

    void print(vi x) {
      if (Debug::DEBG) {
        int xs = x.size();
        FOR(i, 0, xs) {
          cout << x[i] << " ";
        }
        cout << "\n";
      }
    }
    
    void print(vvi x) {
      if (Debug::DEBG) {
        int xs = x.size();
        FOR(i, 0, xs) {
           Debug::print(x[i]);
        }
        cout << "\n";
      }
    }

    
};

Debug dbg;
int N, D;
vi V;
vvvi dp;

long long solve(int i, int j, bool k) { 
  dbg.print((vi){i, j, k});
  
  if (i > j) return 0;
  if (dp[i][j][k] != -1) return dp[i][j][k];
  long long z = 0;
  if (!k && i > 1) {
    z = D - V[i - 1];
  }
  if (k && j < N) {
    z = D - V[j + 1];
  }
  long long ci = (V[i] + z) % D;
  long long cj = (V[j] + z) % D;
  dbg.print((vi){ci, cj});
  
  long long v1 = min(ci, D - ci) + solve(i + 1, j, 0);
  long long v2 = min(cj, D - cj) + solve(i, j - 1, 1);
  
  dp[i][j][k] = min(v1, v2);
  return min(v1, v2);
}

int main()
{
  DEBUG(false)

  int t; cin >> t;
  FOR(i, 1, t + 1) {
    cin >> N >> D;
    V = vi(N + 1);
    FOR(j, 1, N + 1) {
      long long p; cin >> p;
      V[j] = p;
    }
    dbg.print(V);
    dp = vvvi(N + 1, vvi(N + 1, vi(2, -1)));
    long long q = solve(1, N, 0);
    cout << "Case #" << i << ": " << q << endl;
  }
}