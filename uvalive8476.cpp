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

int n, m;
int fa[N];
ll val[N];
int find(int x) {
  if (x == fa[x]) return x;

  int ans = fa[x];
  fa[x] = find(fa[x]);
  val[x] ^= val[ans];
  return fa[x];
}
bool unite(int x, int y, ll w) {
  int fx = find(x);
  int fy = find(y);

  if (fx != fy) {
    fa[fy] = fx;
    val[fy] = w ^ val[x] ^ val[y];
    return true;
  }

  return (w == (val[x] ^ val[y]));
}
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i < n; ++i) {
      int x , y;
      scanf("%d %d", &x, &y);
    }
    for (int i = 0; i <= n; ++i) {
      fa[i] = i;
      val[i] = 0;
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
      int x, y;  ll w;
      scanf("%d %d %lld", &x, &y, &w);
      int fx = find(x);
      int fy = find(y);
      if (!unite(x, y, w) && !ans) {
        ans = i;
      }
    }
    printf("%d\n", ans - 1);
  }
  return 0;
}
