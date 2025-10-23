
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    int n = 140;
    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'M') {
                if (i + 2 < n && j + 2 < n && grid[i + 1][j + 1] == 'A' && grid[i + 2][j + 2] == 'S') {
                    if (grid[i + 2][j] == 'M' && grid[i][j + 2] == 'S') {
                        ans++;
                    }
                    if (grid[i][j + 2] == 'M' && grid[i + 2][j] == 'S') {
                        ans++;
                    }
                }
                if (i - 2 >= 0 && j + 2 < n && grid[i - 1][j + 1] == 'A' && grid[i - 2][j + 2] == 'S') {
                    if (grid[i][j + 2] == 'M' && grid[i - 2][j] == 'S') {
                        ans++;
                    }
                }
                if (i - 2 >= 0 && j - 2 >= 0 && grid[i - 1][j - 1] == 'A' && grid[i - 2][j - 2] == 'S') {
                    if (grid[i - 2][j] == 'M' && grid[i][j - 2] == 'S') {
                        ans++;
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}

