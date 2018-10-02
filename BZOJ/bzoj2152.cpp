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

const int N = 200000 + 20;
const int INF = 0x3f3f3f3f;

int n;
struct Edge {int to, next, val;} e[N * 2];
int ecnt, head[N];
int sum, root, sz[N], f[N], dist[N], d[N], vis[N];
ll ans, tot;
void add_edge(int x, int y, int w) {
  e[ecnt] = {y, head[x], w};
  head[x] = ecnt++;
}
void get_root(int x, int par) {
  sz[x] = 1; f[x] = 0;
  for (int i = head[x]; ~i; i = e[i].next) {
    int v = e[i].to;
    if (v == par || vis[v]) continue;
    get_root(v, x);
    sz[x] += sz[v];
    f[x] = max(f[x], sz[v]);
  }
  f[x] = max(f[x], sum - sz[x]);
  if (f[x] < f[root]) root = x;
}
void get_dist(int x, int par) {
  dist[++dist[0]] = d[x];
  for (int i = head[x]; ~i; i = e[i].next) {
    int v = e[i].to, w = e[i].val;
    if (v == par || vis[v]) continue;
    d[v] = d[x] + w;
    d[v] %= 3;
    get_dist(v, x);
  }
}
int solve(int x, int w) {
  d[x] = w; dist[0] = 0;
  get_dist(x, 0);
  map<int, int> cnt;
  for (int i = 1; i <= dist[0]; ++i) {
    assert(dist[i] >= 0 && dist[i] < 3);
    cnt[dist[i]]++;
  }
  ll ret = 2LL * cnt[1] * cnt[2];
  ret += 1LL * cnt[0] * cnt[0];
  return ret;
}
void dfs(int x) {
  vis[x] = 1;
  
  ans += solve(x, 0);
  for (int i = head[x]; ~i; i = e[i].next) {
    int v = e[i].to, w = e[i].val;
    if (vis[v]) continue;
    ans -= solve(v, w);
    sum = sz[v]; root = 0;
    get_root(v, 0);
    dfs(root);
  }
}
int main(int args, char const *agrv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  
  scanf("%d", &n);
  ecnt = 0; 
  memset(head, -1, sizeof(head));
  for (int i = 1; i < n; ++i) {
    int x, y, w;
    scanf("%d %d %d", &x, &y, &w);
    w %= 3;
    add_edge(x, y, w);
    add_edge(y, x, w);
  }

  ans = 0;
  f[0] = sum = n;
  get_root(1, 0);
  dfs(root);
  tot = n * n;
  ll g = gcd(ans, tot);
  ans /= g; tot /= g;
  printf("%lld/%lld\n", ans, tot);
  return 0;
}