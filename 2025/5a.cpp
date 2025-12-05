#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long int;


int main() {
    int n = 187, m = 1000;

    vector<pair<ull, ull>> actives;

    while (n--) {
        string s; cin >> s;
        size_t index = s.find("-");
        ull left = stoull(s.substr(0, index));
        ull right = stoull(s.substr(index + 1, s.size() - index - 1));
        actives.push_back({left, right});
    }

    sort(actives.begin(), actives.end(), [](const pair<ull, ull> &a, const pair<ull, ull> &b) {
        if (a.first < b.first) return true;
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return false;
    });


    string blank; cin >> blank;
    int counter = 0;

    while (m--) {
        ull id; cin >> id;

        int flag = 0;

        for (int i = 0; i < actives.size(); i++) {
            if (flag == 1) break;

            if (id >= actives[i].first && id <= actives[i].second) {
                counter++;
                flag = 1;
            }
        }
    }

    cout << counter;

    return 0;
}
