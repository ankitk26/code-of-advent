#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long int;
#define present(c,x) ((c).find(x) != (c).end())

int main() {
	int n = 1000;

	vector<vector<ll>> grid(n);

	// take inputs
	for (int i = 0; i < n; i++) {
		string s; cin >> s;

		size_t pos = s.find(",");
		grid[i].push_back(stoi(s.substr(0, pos)));

		s = s.substr(pos + 1);
		pos = s.find(",");
		grid[i].push_back(stoi(s.substr(0, pos)));

		s = s.substr(pos + 1);
		pos = s.find(",");
		grid[i].push_back(stoi(s.substr(0, pos)));
	}

	// calculate distances between all nodes
	vector<pair<pair<ll, ll>, ll>> dist;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			ll x = grid[i][0] - grid[j][0], y = grid[i][1] - grid[j][1], z = grid[i][2] - grid[j][2];
			ll d = x * x + y * y + z * z;
			dist.push_back({{i, j}, d});
		}
	}

	// sort by closest distance
	sort(dist.begin(), dist.end(), [](const auto & p1, const auto & p2) {
		return p1.second < p2.second;
	});


	// create circuits
	unordered_map<int, int> gr;
	int connections = 1000;
	int counter = 1;

	for (int i = 0; i < connections; i++) {
		int p1 = dist[i].first.first, p2 = dist[i].first.second;
		if (present(gr, p1) && !present(gr, p2)) {
			gr[p2] = gr[p1];
		} else if (present(gr, p2) && !present(gr, p1)) {
			gr[p1] = gr[p2];
		} else if (present(gr, p1) && present(gr, p2)) {
			if (gr[p1] == gr[p2]) {
				continue;
			}
			int p2Gr = gr[p2];
			for (auto  k : gr) {
				if (k.second == p2Gr) {
					gr[k.first] = gr[p1];
				}
			}
		} else {
			gr[p1] = counter;
			gr[p2] = counter;
			counter++;
		}
	}

	// calculate sizes of circuits
	unordered_map<int, int> freq;
	for (auto k : gr) {
		freq[k.second]++;
	}
	vector<int> freqArr;
	for (auto k : freq) {
		freqArr.push_back(k.second);
	}
	sort(freqArr.rbegin(), freqArr.rend());

	// for (auto k : freqArr) {
	// 	cout << k << " ";
	// }
	// cout << endl;

	// calculate ans
	ll ans = 1;
	for (int i = 0; i < 3; i++) {
		ans *= freqArr[i];
	}

	cout << ans;

	return 0;
}
