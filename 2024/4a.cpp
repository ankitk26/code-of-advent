#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int checkXmas(int row, int col, vector<string> &grid) {
    int counter = 0;

    // check right
    int n = grid.size(), m = grid[0].size();
    if (col + 3 < m && grid[row].substr(col, 4) == "XMAS") {
        counter++;
    }

    // check left
    if (col - 3 >= 0 && grid[row].substr(col - 3, 4) == "SAMX") {
        counter++;
    }

    // check down
    if (row + 3 < n) {
        string curr;
        for (int i = 0; i < 4; i++) {
            curr += grid[row + i][col];
        }
        if (curr == "XMAS") {
            counter++;
        }
    }

    // check up
    if (row - 3 >= 0) {
        string curr;
        for (int i = 0; i < 4; i++) {
            curr += grid[row - i][col];
        }
        if (curr == "XMAS") {
            counter++;
        }
    }

    // check north-west
    if (row - 3 >= 0 && col - 3 >= 0) {
        string curr;
        for (int i = 0; i < 4; i++) {
            curr += grid[row - i][col - i];
        }
        if (curr == "XMAS") {
            counter++;
        }
    }

    // check north-east
    if (row - 3 >= 0 && col + 3 < m) {
        string curr;
        for (int i = 0; i < 4; i++) {
            curr += grid[row - i][col + i];
        }
        if (curr == "XMAS") {
            counter++;
        }
    }

    // check south-east
    if (row + 3 < n && col + 3 < m) {
        string curr;
        for (int i = 0; i < 4; i++) {
            curr += grid[row + i][col + i];
        }
        if (curr == "XMAS") {
            counter++;
        }
    }

    // check south-west
    if (row + 3 < n && col - 3 >= 0) {
        string curr;
        for (int i = 0; i < 4; i++) {
            curr += grid[row + i][col - i];
        }
        if (curr == "XMAS") {
            counter++;
        }
    }
    return counter;
}

int main() {
    int n = 140;
    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'X') {
                int xmasCount = checkXmas(i, j, grid);
                if (xmasCount > 0) {
                    ans += xmasCount;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
