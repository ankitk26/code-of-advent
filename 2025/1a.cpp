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
		k %= 100;

		if (dir == 'L') {
			dial -= k;
			if (dial < 0) {
				dial += 100;
			}
		} else {
			dial += k;
			dial %= 100;
		}
		if (dial == 0) {
			ans++;
		}
	}

	cout << ans << endl;
	return 0;
}
