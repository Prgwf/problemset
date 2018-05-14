#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 300000 + 20;
const int INF = 0x3f3f3f3f;

int n, u, v, sz[N], fa[N];
vector<vector<int>> T;
void dfs(int x, int p) {
  sz[x] = 1;
  fa[x] = p;
  for (int v : T[x]) {
    if (v != p) {
      dfs(v, x);
      sz[x] += sz[v];
    }
  }
}
int main(int args, char const *argv[]) {
  scanf("%d %d %d", &n, &u, &v);
  T.assign(n + 1, vector<int>());

  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    T[x].push_back(y);
    T[y].push_back(x);
  }
  dfs(u, -1);

  ll ans = 1LL * n * (n - 1);
  ll vsiz = sz[v];
  int f = v;
  while (fa[f] != u) {
    f = fa[f];
  }
  ll left = n - sz[f];
  ans -= left * vsiz;
  printf("%lld\n", ans);
}
