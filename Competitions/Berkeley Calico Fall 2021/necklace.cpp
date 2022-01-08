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

void print(vi x) {
  int xs = x.size();
  FOR(i, 0, xs) {
    cout << x[i] << " ";
  }
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  FOR(i, 0, t) {
    int num, real_num;
    cin >> num;
    real_num = num;
    vi digits;
    while (num > 0) {
      digits.push_back(num % 10);
      num /= 10;
    }

    int n = digits.size();
    int max_int = real_num;
    FOR (j, 1, n) {
      int newn = 0;
      REV (k, j, j + n) {
        newn = newn * 10 + digits[k % n];
      }
      max_int = max(max_int, newn);
    }
    cout << max_int << "\n";    
  }
  return 0;
}