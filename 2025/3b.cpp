
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long int;

unsigned long long getMaxNum(string s) {
	int K = 12;
	int n = s.size();

	string ans = "";
	int lo = 0;

	for (int j = K; j > 0; j--) {
		char maxDigit = '0';
		int maxDigitIndex = -1;

		for (int i = lo; i <= n - j; i++) {
			if (s[i] > maxDigit) {
				maxDigit = s[i];
				maxDigitIndex = i;
				if (maxDigit == '9') break;
			}
		}

		ans.push_back(maxDigit);
		lo = maxDigitIndex + 1;
	}

	return stoull(ans);
}


int main() {
	int n = 200;
	ull sum = 0;

	while (n--) {
		string s; cin >> s;
		ull num = getMaxNum(s);
		// cout << num << endl;
		sum += num;
	}

	cout << sum;

	return 0;
}
