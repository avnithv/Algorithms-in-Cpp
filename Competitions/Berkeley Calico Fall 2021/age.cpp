#include <bits/stdc++.h>
#include <cmath>

using namespace std;

typedef unordered_set<int> us;
typedef vector<int> vi;
typedef vector<char> vc;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

struct ed {int s; int e;};
typedef vector<ed> ve;

struct nd {int h; vi adj; bool end;};
typedef vector<nd> vn;
typedef priority_queue<pii,vector<pii>,greater<pii>> pqmii;
typedef priority_queue<pii> ppii;

#define FOR(i, a, b) for(int i = a; i < b; i++)
#define REV(i, a, b) for(int i = b - 1; i >= a; i--)
#define F first
#define S second


int main() {
  int t;
  cin >> t;
  FOR(i, 0, t) {
    string n1, n2;
    int a1, a2, x, y, z;
    cin >> n1 >> a1 >> n2 >> a2;
    x = min(a1, a2);
    y = max(a1, a2);
    z = y - 2 * x;
    if (z <= 0) {
      cout << "Time will end before you are happy\n";
    } else {
      cout << "In " << z << " year(s):\n" << n1 << " will be " << a1 + z << " and " << n2 << " will be " << a2 + z << "\n";
    }
    if (i != t - 1) cout << "\n";
  }
  return 0;
}