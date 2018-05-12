#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100 + 20;
const int INF = 0x3f3f3f3f;

int n, m;
bool g[N][N];
int a[N], pos[N];
int main(int args, char const *argv[]) {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    pos[i] = i;
  }
  scanf("%d", &m);
  while (m--) {
    int opt, x, y, k;
    scanf("%d", &opt);
    if (opt) {
      scanf("%d %d %d", &k, &x, &y);
      for (int i = x; i <= y; ++i) {
        g[pos[k]][pos[i]] = 1;
      }
    } else {
      scanf("%d %d", &k, &x);
      a[++n] = x;
      pos[k] = n;
    }
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        g[i][j] |= (g[i][k] & g[k][j]);
      }
    }
  }
  ll ans= 4e18;
  for (int i = 1; i <= n; ++i) {
    ll c = a[i];
    for (int j = 1; j <= n; ++j) if (i != j) {
      if (g[i][j]) c += a[j];
    }
    ans = min(ans, c);
  }
  printf("%lld\n", ans);
}
