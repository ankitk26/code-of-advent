#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long int;

int dfs(unordered_map<int, vector<int>> &graph, int start, int end) {
	if (start == end) {
		return 1;
	}

	int ans = 0;
	for (int i = 0; i < graph[start].size(); i++) {
		ans += dfs(graph, graph[start][i], end);
	}

	return ans;
}

int main() {
	int n = 576;

	unordered_map<int, vector<int>> graph;
	unordered_map<string, int> words;

	int c = 0;
	int start = -1, end = -1;

	for (int i = 0; i < n; i++) {
		string s; getline(cin, s);
		int pos = s.find(":");

		string from = s.substr(0, pos);
		int src;

		if (words.find(from) == words.end()) {
			words[from] = c;
			src = c;
			if (from == "you" && start == -1) {
				start = c;
			} else if (from == "out" && end == -1) {
				end = c;
			}
			c++;
		} else {
			src = words[from];
		}

		s = s.substr(pos + 2);

		while (1) {
			pos = s.find(" ");
			string curr;

			if (pos == -1) {
				curr = s;
			} else {
				curr = s.substr(0, pos);
			}
			int tgt;

			if (curr == "you" && start == -1) {
				start = c;
			} else if (curr == "out" && end == -1) {
				end = c;
			}

			if (words.find(curr) == words.end()) {
				words[curr] = c;
				tgt = c;
				c++;
			} else {
				tgt = words[curr];
			}

			graph[src].push_back(tgt);

			if (pos == -1) {
				break;
			}

			s = s.substr(pos + 1);
		}
	}

	int pathsCount = dfs(graph, start, end);
	cout << pathsCount;

	return 0;
}
