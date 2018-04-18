#include <bits/stdc++.h>
using namespace std;

const int N = 567;
const int inf = 0x3f3f3f3f;

int h, w;
char grid[N][N];

int dist[2][N][N];

struct State {
  int x, y, k;
} ;

queue<State> Q;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int stx, sty;
int main() {
  scanf("%d %d", &h, &w);
  for (int i = 0; i < h; ++i) scanf("%s", grid[i]);

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (grid[i][j] == 'S') {
        stx = i; sty = j;
        goto work;
      }
    }
  }

work:
  grid[stx][sty] = '.';
  memset(dist, 0xff, sizeof(dist));
  dist[0][stx][sty] = 0;
  Q.push({stx, sty, 0});
  
  while (Q.size()) {
    auto T = Q.front();
    Q.pop();

    for (int i = 0; i < 4; ++i) {
      int x = T.x + dx[i];
      int y = T.y + dy[i];
      int k = T.k;

      if (grid[x][y] == 'E') {
        int ret1 = dist[0][T.x][T.y];
        int ret2 = dist[1][T.x][T.y];
        if (ret1 < 0) ret1 = inf;
        if (ret2 < 0) ret2 = inf;
        int ans = min(ret1, ret2) + 1;
        printf("%d\n", ans);
        return 0;
      }

      if (grid[x][y] == 'W') continue;

      if (grid[x][y] == 'D') {
        if (k) {
          if (dist[1][x][y] < 0 or dist[1][x][y] > dist[1][T.x][T.y] + 1) {
            dist[1][x][y] = dist[1][T.x][T.y] + 1;
            Q.push({x, y, 1});
          }
        } else {
          ;
        }
        continue;
      }

      if (grid[x][y] == 'K') {
        if (dist[1][x][y] < 0 or dist[1][x][y] >  dist[0][T.x][T.y] + 1) {
          dist[1][x][y] = dist[0][T.x][T.y] + 1;
          Q.push({x, y, 1});
        }
        continue;
      }

      if (grid[x][y] == '.') {
        if (dist[k][x][y] < 0 or dist[k][x][y] > dist[k][T.x][T.y] + 1) {
          dist[k][x][y] = dist[k][T.x][T.y] + 1;
          Q.push({x, y, k});
        }
        continue;
      }
    }
  }

  printf("-1\n");
  return 0;
}