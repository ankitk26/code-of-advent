#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long int;


int main() {
	int n = 5;

	vector<string> grid;

	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		grid.push_back(s);
	}

	vector<ll> nums;
	ll ans = 0;

	for (int j = grid[0].size() - 1; j >= 0; j--) {
		string curr;
		for (int i = 0; i < n; i++) {
			if (grid[i][j] == '*' || grid[i][j] == '+') {
				if (curr.size() > 0) {
					nums.push_back(stoll(curr));
				}
				char op = grid[i][j];

				ll currTotal = 0;
				if (op == '*') {
					currTotal = 1;
				}

				for (auto k : nums) {
					if (op == '+') {
						currTotal += k;
					} else {
						currTotal *= k;
					}
				}
				ans += currTotal;
				nums.clear();
				curr = "";
			} else if (grid[i][j] != ' ') {
				curr += grid[i][j];
			}
		}
		if (curr.size() > 0) {
			nums.push_back(stoll(curr));
		}
	}

	cout << ans;

	return 0;
}
