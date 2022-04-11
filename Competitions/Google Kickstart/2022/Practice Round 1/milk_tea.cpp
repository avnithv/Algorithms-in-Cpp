#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef vector<pii> vpii;
typedef vector<pis> vpis;

typedef priority_queue<pis> pqpis;

#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FE(x, s) for(auto x : s)
#define PSH push_back
#define POP pop_back
#define MP(a, b) make_pair(a, b)
#define F first
#define S second
#define endl "\n"

bool DEBG = true;
string useles;

pqpis sk;
vi fr;
unordered_set<string> st;
int N, M, P;

void print(int s) {
  if (DEBG) cout << s << endl;
}

void print(string s) {
  if (DEBG) cout << s << endl;
}

void print(vi x) {
  if (DEBG) {
    int xs = x.size();
    FOR(i, 0, xs) {
      cout << x[i] << " ";
    }
    cout << "\n";
  }
}

void print(pis z) { 
  if (DEBG) {
    cout << z.F << " " << z.S << endl;
  }  
}

void print(pqpis x) {
  if (DEBG) {
    pqpis q;
    while (!x.empty()) {
      pis z = x.top(); x.pop();
      q.push(z);
      print(z);
    }
    cout << endl;
    x.swap(q);
  }
}

void print(unordered_set<string> x) {
  if (DEBG) {
    FE(z, x) {
      cout << z << " ";
    }
    cout << endl;
  }
}

void addk(int k) {
  print(k);
  pqpis n;
  while (!sk.empty()) {
    pis z = sk.top(); sk.pop();
    n.push(MP(z.F + fr[k], z.S + "0"));
    n.push(MP(z.F - N - fr[k], z.S + "1"));
  }
  int z = min((signed) n.size(), M + 1);
  FOR (i, 0, z) {
    sk.push(n.top()); n.pop();
  }
}

int solve() {
  cin >> N >> M >> P;
  fr.erase(fr.begin(), fr.end()); fr.resize(P);
  FOR(i, 0, N) {
    FOR(j, 0, P) {
      char ch; cin >> ch;
      fr[j] -= ch - '0';
    }
  }
  print(fr);
  st.erase(st.begin(), st.end());
  getline(cin, useles);
  FOR(k, 0, M) {
    getline(cin, useles);
    st.insert(useles);
    print(st);
  }
  sk = {}; 
  sk.push(MP(0, ""));
  print("d");
  FOR(p, 0, P) {
    addk(p);
    print(sk);
  }
  pis ans = sk.top(); sk.pop();
  while (st.count(ans.S) > 0) {
    print(ans.S);
    ans = sk.top(); sk.pop();
  }
  return abs(ans.F);
}

int main() {
  int t, T; cin >> t; T = t;
  while (t --> 0) {
    auto ans = solve();
    cout << "Case #" << T - t << ": " << ans << endl;
  }
  return 0;
}
