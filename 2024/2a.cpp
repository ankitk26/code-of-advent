#include <bits/stdc++.h>
using namespace std;
#define ll long long int


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

        int flag = 0;

        if (v[1] == v[0]) {
            continue;
        }

        if (v[1] > v[0]) {
            for (int i = 1; i < v.size(); i++) {
                if (v[i] <= v[i - 1]) {
                    flag = 1;
                    break;
                } else {
                    if (v[i] - v[i - 1] > 3) {
                        flag = 1;
                        break;
                    }
                }
            }
        } else {
            for (int i = 1; i < v.size(); i++) {
                if (v[i] >= v[i - 1]) {
                    flag = 1;
                    break;
                } else {
                    if (v[i - 1] - v[i] > 3) {
                        flag = 1;
                        break;
                    }
                }
            }
        }

        if (flag == 0) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}
