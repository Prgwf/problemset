#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<limits.h>
#include<assert.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 500 + 20;
const int INF = 0x3f3f3f3f;

int n, m;
char g[N][N];
int vis[N][N];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char mp[] = {'U', 'D', 'L', 'R'};
vector<int> path;
void dfs(int x, int y, int d) {
  vis[x][y] = 1;
  if (d != -1) path.push_back(d);
  for (int i = 0; i < 4; ++i) {
    int tx = x + dx[i];
    int ty = y + dy[i];
    if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
    if (vis[tx][ty]) continue;
    if (g[tx][ty] != '.') continue;
    dfs(tx, ty, i);
  }
  if (d != -1) path.push_back(d^1);
}
int main(int args, char const *agrv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%s", g[i] + 1);
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
    if (g[i][j] == 'P') {
      dfs(i, j, -1);
      for (int d : path) {
        putchar(mp[d]);
      }
      // for (int i = 1; i <= n; ++i) {
      //   for( int j = 1; j <= m; ++j) {
      //     printf("%c", vis[i][j] ? '#':'*');
      //   }
      //   puts("");
      // }
      return 0;
    }
  }
  return 0;
}