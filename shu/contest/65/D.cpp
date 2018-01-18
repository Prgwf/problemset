/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

char grid[4][4];
int step[1 << 17][4][4][4][4];
int n, m;
struct State {
  int state, x1, y1, x2, y2;
} ;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool check(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m) {
    return 0;
  }

  if (grid[x][y] == 'X') {
    return 0;
  }

  return 1;
}
void work() {
  int T;
  cin >> T;

  int kase = 0;
  while (T--) {

    cin >> n >> m;

    int sx, sy;
    int T = (1 << (n * m)) - 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> grid[i][j];
        if (grid[i][j] == 'S') {
          sx = i;
          sy = j;
        } else if (grid[i][j] == 'X') {
          T ^= 1 << (i * m + j);
        }
      }
    }

    queue<State> Q;
    memset(step, -1, sizeof(step));
    int S = sx * m + sy;
    Q.push({1 << S, sx, sy, sx, sy});
    step[1 << S][sx][sy][sx][sy] = 0;
    int ans = 0;

    while (Q.size()) {
      State now = Q.front();
      Q.pop();

      int curs = now.state;
      int x1 = now.x1;
      int y1 = now.y1;
      int x2 = now.x2;
      int y2 = now.y2;

      for (int i = 0; i < 4; ++i) {
        int tx1 = x1 + dx[i];
        int ty1 = y1 + dy[i];
        if (!check(tx1, ty1)) continue;
        for (int j = 0; j < 4; ++j) {
          int tx2 = x2 + dx[j];
          int ty2 = y2 + dy[j];
          if (!check(tx2, ty2)) continue;

          int ts = curs;
          ts |= 1 << (tx1 * m + ty1);
          ts |= 1 << (tx2 * m + ty2);
          if (step[ts][tx1][ty1][tx2][ty2] < 0) {
            step[ts][tx1][ty1][tx2][ty2] = step[curs][x1][y1][x2][y2] + 1;
            Q.push({ts, tx1, ty1, tx2, ty2});
            if (ts == T) {
              ans = step[ts][tx1][ty1][tx2][ty2];
              goto out;
            }
          }
        }
      }
    }
    out: ;
    cout << "Case #" << ++kase << ": "<< ans<< "\n";
  }
}
int main() {
  freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
