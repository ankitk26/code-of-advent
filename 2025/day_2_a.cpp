#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long int;

ull sumInvalids(string id1, string id2) {
  ull n1 = stoull(id1), n2 = stoull(id2);

  ull sum = 0;
  for (ull n = n1; n <= n2; n++) {
    ull k = log10(n) + 1;
    if (k % 2 == 1) {
      continue;
    }
    k /= 2;
    ull ten = pow(10, k) + 1e-9;
    if ((int)(n / ten) == n % ten) {
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
