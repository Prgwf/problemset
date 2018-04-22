#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  
  bool hasPath(char* matrix, int rows, int cols, char* str) {
    if (matrix == nullptr or str == nullptr) {
      return false;
    }

    R = rows, C = cols;
    g_found = false;
    vis.assign(rows, vector<bool>(cols, false));

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (matrix[i * C + j] == str[0]) {
          dfs(matrix, str, i, j, 1);

          if (g_found) {
            break;
          }
        }
      }
    }

    return g_found;
  }

  bool check(int x, int y) {
    if (x < 0 or x >= R or y < 0 or y >= C
      or vis[x][y]) {
      return false;
    }

    return true;
  }

  void dfs(char *matrix, char *str, int x, int y, int cnt) {
    if (g_found or str[cnt] == '\0') {
      g_found = true;
      return;
    }

    vis[x][y] = true;

    for (int i = 0; i < 4; ++i) {
      int tx = x + dx[i];
      int ty = y + dy[i];

      if (check(tx, ty) 
          && matrix[tx * C + ty] == str[cnt]) {
        vis[tx][ty] = true;
        dfs(matrix, str, tx, ty, cnt + 1);
        vis[tx][ty] = false;
      }
    }
    vis[x][y] = false;
  }

  vector<vector<bool> > vis;
  int R, C;
  bool g_found;
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
};