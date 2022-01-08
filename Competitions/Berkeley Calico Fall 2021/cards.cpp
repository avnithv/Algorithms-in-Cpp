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

string apex = "/\\";
ifstream file;

int main() {
  file.open("cards.in.txt");
  
  int t;
  file >> t;
  FOR(i, 0, t) {
    int n;
    file >> n;
    FOR(j, 1, n + 1) {
      FOR(k, 0, n - j) cout << " ";
      FOR(k, 0, j) cout << apex;
      cout << "\n";
    }
  }
  return 0;
}