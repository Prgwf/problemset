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
const int mod = 1e9 + 7;
#define lson l,m,o<<1
#define rson m+1,r,o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;
const int LGN = 22;

int n, m;
int root, depth[N], fa[LGN][N];
ll dis[N], ans;
vector<pair<int, int>> T[N];
void add_edge(int x, int y, int w) {
  T[x].emplace_back(y, w);
  T[y].emplace_back(x, w);
}
void dfs(int u, int p, int d) {
  fa[0][u] = p;
  depth[u] = d;
  for (int i = 0; i < (int)T[u].size(); ++i) {
    int v = T[u][i].first;
    int w = T[u][i].second;
    if (v != p) {
      dis[v] = (dis[u] + 1LL * w) % mod;
      dfs(v, u, d + 1);
    }
  }
}
int lca(int u, int v) {
  if (depth[u] > depth[v]) swap(u, v);
  for (int k = 0; k < LGN; k++) {
    if ((depth[v] - depth[u]) >> k & 1) {
      v = fa[k][v];
    }
  }
  if (v == u) return u;
  for (int k = LGN - 1; k >= 0; k--) {
    if (fa[k][u] != fa[k][v]) {
      u = fa[k][u];
      v = fa[k][v];
    }
  }
  return fa[0][u];
}
ll get_dist(int u, int v) {
  int f = lca(u, v);
  ll ret = dis[u] + dis[v] - 2 * dis[f];
  // printf("%d %d %d %lld\n", u, v, f, ret);
  while (ret < 0) ret = (ret + mod) % mod;
  return ret;
}
int main(int args, char const *argv[]) {
#ifdef LOCAL_TEST
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  scanf("%d", &n);
  ans = 0;
  for (int i = 1; i < n; ++i) {
    int x, y, z, l;
    scanf("%d %d %d %d", &x, &y, &z, &l);
    if (l & 1) {
      add_edge(x, y, mod - z);
      ans += 1LL * (l + 1) * z % mod;
      ans %= mod;
    } else {
      add_edge(x, y, z);
      ans += 1LL * l * z % mod;
      ans %= mod;
    }
  }
  dfs(1, -1, 0);
  for (int k = 0; k + 1 < LGN; ++k) {
    for (int v = 1; v <= n; ++v) {
      if (fa[k][v] < 0) fa[k + 1][v] = -1;
      else fa[k + 1][v] = fa[k][fa[k][v]];
    }
  }
  scanf("%d", &m);
  while (m--) {
    int s, t;
    scanf("%d %d", &s, &t);
    ll out =(ans +  get_dist(s, t)) % mod;
    printf("%lld\n", out);
  }
  return 0;
}

