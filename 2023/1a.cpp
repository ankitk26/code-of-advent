#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long int;


int main() {
  int n = 1000;

  int sum = 0;
  while (n--) {
    string s; cin >> s;
    int n1 = -1, n2 = -1;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] >= '0' && s[i] <= '9') {
        if (n1 == -1) {
          n1 = s[i] - '0';
          n2 = s[i] - '0';
        } else {
          n2 = s[i] - '0';
        }
      }
    }
    sum += (n1 * 10 + n2);
  }

  cout << sum;

  return 0;
}
