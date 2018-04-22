#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int movingCount(int threshold, int rows, int cols) {
    if (threshold < 0) {
      return 0;
    }
    k = threshold;
    n = rows, m = cols;

    vis.assign(rows, vector<bool>(cols, false));
    ans = 0;
    
    dfs(0, 0);

    return ans;
  }

  void dfs(int x, int y) {
    if (vis[x][y]) {
      return;
    }

    ++ans;
    vis[x][y] = true;
    for (int i = 0; i < 4; ++i) {
      int tx = x + dx[i];
      int ty = y + dy[i];

      if (check(tx, ty)) {
        dfs(tx, ty);
      }
    }
  }

  bool check(int x, int y) {
    if (x < 0 or x >= n or y < 0 or y >= m) {
      return false;
    }

    int sum = 0;
    while (x or y) {
      if (x) {
        sum += x % 10;
        x /= 10;
      }

      if (y) {
        sum += y % 10;
        y /= 10;
      }
    }
    return sum <= k;
  }

  int n, m;
  vector<vector<bool>> vis;
  int ans, k;
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
};