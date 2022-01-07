#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    char first;
    int rounds;
    cin >> first >> rounds;
    bool player = false;
    if (first == 'B') player = true;
    vector<int> score(2, 0);
    
    for (int i = 0; i < rounds; i++) {
      int round;
      cin >> round;
      if (round % 2 == 1) score[player]++;
      else player = !player;
    }
    cout << score[0] << "-" << score[1] << "\n";
  }
}