#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long int;

int numFromWord(string s, int i, int hi) {
  int wnum = -1;

  if (s[i] == 'o' && i + 2 < hi && s.substr(i, 3) == "one") {
    wnum = 1;
  } else if (s[i] == 't') {
    if (i + 2 < hi && s.substr(i, 3) == "two") {
      wnum = 2;
    }
    if (i + 4 < hi && s.substr(i, 5) == "three") {
      wnum = 3;
    }
  } else if (s[i] == 'f') {
    if (i + 3 < hi && s.substr(i, 4) == "four") {
      wnum = 4;
    }
    if (i + 3 < hi && s.substr(i, 4) == "five") {
      wnum = 5;
    }
  } else if (s[i] == 's') {
    if (i + 2 < hi && s.substr(i, 3) == "six") {
      wnum = 6;
    }
    if (i + 4 < hi && s.substr(i, 5) == "seven") {
      wnum = 7;
    }
  }  else if (s[i] == 'e' && i + 4 < hi && s.substr(i, 5) == "eight") {
    wnum = 8;
  } else if (s[i] == 'n' && i + 3 < hi && s.substr(i, 4) == "nine") {
    wnum = 9;
  }

  return wnum;
}

int main() {
  int n = 1000;

  int sum = 0;
  while (n--) {
    string s; cin >> s;

    int n1 = -1, n2 = -1;
    int k = s.size();


    // find first and last digit in numeric form
    for (int i = 0; i < k; i++) {
      if (s[i] >= '0' && s[i] <= '9') {
        if (n1 == -1) {
          n1 = i;
          n2 = i;
        } else {
          n2 = i;
        }
      }
    }

    // first and last digit in word form
    int w1 = -1, w2 = -1;

    // this means all numbers are in word form
    if (n1 == -1) {
      n1 = n;
    }

    // find first word digit before n1
    for (int i = 0; i < n1; i++) {
      if (w1 != -1) {
        break;
      }
      w1 = numFromWord(s, i, n1);
    }

    // find last word digit after n2
    for (int i = k - 1; i > n2; i--) {
      if (w2 != -1) {
        break;
      }
      w2 = numFromWord(s, i, k);
    }

    int curr = 0;

    if (w1 == -1) {
      curr += (s[n1] - '0') * 10;
    } else {
      curr += w1 * 10;
    }

    if (w2 == -1) {
      curr += s[n2] - '0';
    } else {
      curr += w2;
    }

    sum += curr;
  }

  cout << sum;

  return 0;
}
