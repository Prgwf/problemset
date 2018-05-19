#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;

int n, m, k;
int dir[11][10005];
int grid[11][10005];
int vis[11][10005];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int ans = 0;
void dfs(int x0, int y0) {
  if (vis[x0][y0]) return;

  ans++;
  vis[x0][y0] = 1;
  for (int i = 0; i < 4; ++i) {
    int tx = x0 + dx[i];
    int ty = y0 + dy[i];
    if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
    if (dir[tx][ty] != -1 && ((i & 1) == dir[tx][ty])) {
      int wx = tx + dx[i];
      int wy = ty + dy[i];
      if (wx < 1 || wx > n || wy < 1 || wy > m) continue;
      assert(dir[wx][wy] == dir[tx][ty]);

      dir[wx][wy] = -1;
      dir[x0][y0] = i & 1;
      dfs(wx, wy);
      dir[x0][y0] = -1;
      dir[wx][wy] = i & 1;
    }
  }
}
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);

  while (scanf("%d %d %d", &n, &m, &k) != EOF) {

    memset(grid, 0, sizeof(grid));
    memset(dir, 0, sizeof(dir));
    for(int i = 0; i < k; ++i) {
      int x1, y1, x2, y2;
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      assert(x1 == x2 || y1 == y2);
      int d = (y1 == y2);
      dir[x1][y1] = dir[x2][y2] = d;
      grid[x1][y1] = grid[x2][y2] = 1;
    }
    int x0, y0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (!grid[i][j]) {
          x0 = i; y0 = j;
          dir[x0][y0] = -1;
        }
      }
    }

    ans = 0;
    memset(vis, 0, sizeof(vis));
    dfs(x0, y0);
    printf("%d\n", ans - 1);
  }
}
