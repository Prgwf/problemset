#include <bits/stdc++.h>
using namespace std;
#define lson o<<1
#define rson o<<1|1
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;

int n, m;
int fa[N], val[N];
int find(int x) {
  if (x == fa[x]) return x;

  int ans = fa[x];
  fa[x] = find(fa[x]);
  val[x] ^= val[ans];
  return fa[x];
}
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  scanf("%d %d", &n, &m);
  for (int i = 0; i <= n; ++i) {
    fa[i] = i;
    val[i] = 0;
  }
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    int x, y, c;
    scanf("%d %d %d", &x, &y, &c);
    x--;
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) {
      if ((val[x] ^ val[y]) != c) {
        ans++;
        printf("%d\n", i + 1);
      }
    } else {
      fa[fy] = fx;
      val[fy] = c ^ val[x] ^ val[y];
    }
  }

  if (ans == 0) {
    puts("-1");
  }
  return 0;
}
