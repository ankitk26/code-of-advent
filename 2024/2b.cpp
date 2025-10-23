#include <bits/stdc++.h>
using namespace std;
#define ll long long int


bool check(vector<int> v) {
    if (v[1] == v[0]) {
        return 0;
    }

    if (v[1] > v[0]) {
        for (int i = 1; i < v.size(); i++) {
            if (v[i] <= v[i - 1]) {
                return 0;
            } else {
                if (v[i] - v[i - 1] > 3) {
                    return 0;
                }
            }
        }
    } else {
        for (int i = 1; i < v.size(); i++) {
            if (v[i] >= v[i - 1]) {
                return 0;
            } else {
                if (v[i - 1] - v[i] > 3) {
                    return 0;
                }
            }
        }
    }

    return 1;

}

int main() {
    int t = 1000;

    int ans = 0;

    while (t--) {
        string s;
        getline(cin, s);

        vector<int> v;
        string curr;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                v.push_back(stoi(curr));
                curr = "";
            } else {
                curr += s[i];
            }
        }
        v.push_back(stoi(curr));
        // for (auto k: v) {
        //     cout << k << " ";
        // }
        for (int i = 0; i < v.size(); i++) {
            vector<int> tempV;
            for (int j = 0; j < v.size(); j++) {
                if (j == i) {
                    continue;
                }
                tempV.push_back(v[j]);
            }

            if (check(tempV)) {
                ans++;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}
