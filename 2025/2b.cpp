#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long int;

bool isValidDivision(string s, int k) {
  string firstPart = s.substr(0, k);

  for (int i = k; i < s.size(); i += k) {
    string curr = s.substr(i, k);
    if (curr != firstPart) {
      return false;
    }
  }

  return true;

}

bool isValid(ull n) {
  string s = to_string(n);

  for (int i = 1; i <= s.size() / 2; i++) {
    if (s.size() % i != 0) {
      continue;
    }

    if (isValidDivision(s, i)) {
      return true;
    }

  }

  return false;
}

ull sumInvalids(string id1, string id2) {
  ull n1 = stoull(id1), n2 = stoull(id2);

  ull sum = 0;
  for (ull n = n1; n <= n2; n++) {
    if (isValid(n)) {
      sum += n;
    }
  }

  return sum;
}

int main() {
  string s;
  cin >> s;

  string id1 = "", id2 = "";
  int flag = 0;

  ull invalids = 0;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '-') {
      flag = 1;
      continue;
    }
    if (s[i] == ',') {
      flag = 0;
      invalids += sumInvalids(id1, id2);
      id1 = "";
      id2 = "";
      continue;
    }
    if (flag == 0) {
      id1 += s[i];
    } else {
      id2 += s[i];
    }
  }

  invalids += sumInvalids(id1, id2);

  cout << invalids;

  return 0;
}
