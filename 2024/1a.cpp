#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int main() {
    vector<ll> v1;
    vector<ll> v2;

    int n = 1000;

    while (n--) {
        ll a, b; cin >> a >> b;
        v1.push_back(a);
        v2.push_back(b);
    }

    ll sum = 0;
    for (int i = 0; i < v1.size(); i++) {
        sum += abs(v1[i] - v2[i]);
    }

    cout << sum << endl;

    return 0;
}
