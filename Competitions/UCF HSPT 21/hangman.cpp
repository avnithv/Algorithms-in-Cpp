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

#define FOR(i, a, b) for(int i = a; i < b; i++)
#define REV(i, a, b) for(int i = b - 1; i >= a; i--)
#define f first
#define s second



vn makeAdjMat(int ne) {
  vn matrix;
  matrix.push_back({-1, vi(26, -1), false});
  FOR(j, 0, ne) {
    string s;
    getline(cin, s);
    int x = 0;
    FOR(i, 0, s.length()) {
      int d = s[i] - 97;
      if (matrix[x].adj[d] != -1) {
        x = matrix[x].adj[d];
      } else {
        nd y = {d, vi(26, -1), false};
        matrix[x].adj[d] = matrix.size();
        matrix.push_back(y);
        x = matrix.size() - 1;
      }
    }
    matrix[x].end = true;
  }
  return matrix;
}

bool serch(vn x, string s, int ind, int gues[]) {
  nd z = x[ind];
  if (s.length() == 0) return z.end;
  if (s[0] == '_') {
    FOR(i, 0, 26) {
      if (gues[i] != 1 && z.adj[i] != -1 &&serch(x, s.substr(1), z.adj[i], gues)) {
        return true;
      }
    }
    return false;
  }
  int i = z.adj[s[0] - 97];
  if (i == -1) return false;
  return serch(x, s.substr(1), i, gues);
}

int main() {
  int cases;
  cin >> cases;
  string f;
  getline(cin, f);
  for (int iol = 0; iol < cases; iol++) {
    string name;
    getline(cin, name);
    
    int w;
    cin >> w;
    getline(cin, f);
    
    vn trie = makeAdjMat(w);
    int g;
    cin >> g;
    getline(cin, f);
    FOR(i, 0, g) {
      string z;
      getline(cin, z);
      int gues[26] =  {0};
      for (char ch : z) gues[ch - 97] = 1;
      if (serch(trie, z, 0, gues)) cout << "No cheaters here!\n";
      else cout << "That's not a word for a(n) " << name << "!\n";
    }
  }
  return 0;
}