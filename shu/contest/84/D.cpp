/*
教练我想打ACM~
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 500 + 20;

int n, m;
char grid[maxn][maxn];
int main() {
  while (scanf("%d%d", &n, &m)) {
    if(!(n + m)) break;
    memset(grid, 0, sizeof(grid));
    for (int i = 0; i < n; ++i) {
      scanf("%s", grid[i]);
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == '.') {
          int cnt = 0;
          for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
              if (dx || dy) {
                int x = i + dx;
                int y = j + dy;
                if (x < 0 || x >= n || y < 0 || y >= m) continue;
                if (grid[x][y] == 'x') {
                  ++cnt;
                }
              }
            }
          }
          grid[i][j] = '0' + cnt;
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      printf("%s\n", grid[i]);
    }
  }
}
