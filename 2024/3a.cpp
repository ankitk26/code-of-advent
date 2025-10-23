#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(string s) {
    int n = s.size();
    ll ans = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'm' && i + 3 < n && s.substr(i, 4) == "mul(") {
            int index = i + 4;
            string curr = "";
            int n1 = 1, n2 = 1;
            while (index < n && s[index] != ',') {
                curr += s[index];
                index++;
            }
            if (curr.size() > 3) {
                continue;
            }
            int flag = 0;
            for (auto k : curr) {
                if (k < '0' || k > '9') {
                    flag = 1;
                }
            }
            if (flag == 1) {
                continue;
            }
            n1 = stoi(curr);

            index++;
            curr = "";
            flag = 0;

            while (index < n && s[index] != ')') {
                curr += s[index];
                index++;
            }
            if (curr.size() > 3) {
                continue;
            }
            for (auto k : curr) {
                if (k < '0' || k > '9') {
                    flag = 1;
                }
            }
            if (flag == 1) {
                continue;
            }

            n2 = stoi(curr);
            ans += (n1 * n2);
        }
    }
    cout << ans << endl;
}

int main() {
    string bigS;
    while (true) {
        string s;
        getline(cin, s);
        if (s == "") {
            break;
        }
        bigS += s;
    }
    solve(bigS);
    return 0;
}
