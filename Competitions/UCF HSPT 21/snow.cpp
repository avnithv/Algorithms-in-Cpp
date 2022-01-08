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

int nn;
vector<bool> destroyed;
string usless;

void fill(int a, int b, bool d) {
  while (b) {
    a %= nn;
    if (!destroyed[a]) destroyed[a] = true;
    else b++;

    if (d) a++;
    else a--;
    b--;
  }
}

int main() {
  int t;
  cin >> t;
  FOR(i, 0, t) {
    cin >> nn;

    ppii hs;
    vector<bool> des;
    FOR(j, 0, nn) {
      int hh;
      cin >> hh;
      hs.push(make_pair(hh, j * -1));
      des.push_back(false);
    }
    destroyed = des;
    char ch; int z = 0, s = 0;
    while (true) {
      pii q = hs.top(); hs.pop();
      if (destroyed[-1 * q.S]) continue;
      cin >> ch;

      z += q.F;
      if (z >= nn) break;
      fill(-1 * q.S, q.F, ch == 'R');
      s++;
    }
    getline(cin, usless);
    cout << s + 1 << "\n";
  }
  return 0;
}