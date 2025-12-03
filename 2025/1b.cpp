#include <bits/stdc++.h>
using namespace std;


int main() {
  int n = 4145;

  int dial = 50;
  int ans = 0;

  while (n--) {
    string s; cin >> s;
    char dir = s[0];

    int k = stoi(s.substr(1, s.size() - 1));
    int modK = k % 100;

    if (dir == 'L') {
      if (k >= 100) {
        ans += k / 100;
      }

      int flag = 1;
      if (dial > 0 && dial - modK <= 0) {
        ans++;
      }
      dial -= modK;
      if (dial < 0) {
        dial += 100;
      }
    } else {
      if (k >= 100) {
        ans += k / 100;
      }

      if (dial + modK > 99) {
        ans++;
      }
      dial += modK;
      dial %= 100;
    }
    // cout << dial << endl;
  }

  cout << ans << endl;
  return 0;
}
