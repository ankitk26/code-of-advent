#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long int;


int removeRolls(vector<string> &grid) {
  int n = grid.size();
  int counter = 0;

  int xr[8] = {0, 1, 0, -1, 1, -1, 1, -1};
  int yr[8] = {1, 0, -1, 0, 1, 1, -1, -1};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < grid[i].size(); j++) {
      if (grid[i][j] == '@') {
        int ne = 0;
        for (int k = 0; k < 8; k++) {
          if (i + xr[k] < n && i + xr[k] >= 0 && j + yr[k] < grid[i].size() && j + yr[k] >= 0 && grid[i + xr[k]][j + yr[k]] == '@') {
            ne++;
          }
        }
        if (ne < 4) {
          grid[i][j] = '.';
          counter++;
        }
      }
    }
  }

  return counter;
}

int main() {
  int n = 135;

  vector<string> grid(n);
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }

  int totalRolls = 0;

  while (1) {
    int rolls = removeRolls(grid);
    if (rolls == 0) {
      break;
    }
    totalRolls += rolls;
  }

  cout << totalRolls;

  return 0;
}
