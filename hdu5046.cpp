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

const int N = 5000 + 20;
const int INF = 0x3f3f3f3f;
const int maxnnode = 5e5 + 20;

struct DLX {
  int n, m, id;
  int U[maxnnode], D[maxnnode], L[maxnnode], R[maxnnode];
  int row[maxnnode], col[maxnnode];
  int S[N], H[N];
  int ansd, ans[N];
  bool vis[maxnnode];

  void init(int n, int m) {
    this->n = n; this->m = m;
    this->ansd = INF;
    for (int i = 0; i <= m; ++i) {
      S[i] = 0;
      U[i] = D[i] = i;
      L[i] = i - 1;
      R[i] = i + 1;
    }
    R[m] = 0; L[0] = m;
    id = m;
    for (int i = 1; i <= n; ++i) {
      H[i] = -1;
    }
    memset(vis, 0, sizeof(vis));
  }

  void link(int r, int c) {
    ++S[col[++id] = c];
    row[id] = r;
    D[id] = D[c];
    U[D[c]] = id;
    U[id] = c;
    D[c] = id;
    if (H[r] < 0) {
      H[r] = L[id] = R[id] = id;
    } else {
      R[id] = R[H[r]];
      L[R[H[r]]] = id;
      L[id] = H[r];
      R[H[r]] = id;
    }
  }
  bool dance(int d, int limit) {
    if (d > limit || d + check() > limit) return false;
    if (R[0] == 0) {
      ansd = d;
      return true;
    }

    int c = R[0];
    for (int i = R[0]; i != 0; i = R[i]) {
      if (S[i] < S[c]) {
        c = i;
      }
    }
    for (int i = D[c]; i != c; i = D[i]) {
      ans[d] = row[i];
      remove(i);
      for (int j = R[i]; j != i; j = R[j]) {
        remove(j);
      }
      if (dance(d + 1, limit)) return true;
      for (int j = L[i]; j != i; j = L[j]) {
        restore(j);
      }
      restore(i);
    }
    return false;
  }

  void remove(int c) {
    for (int i = D[c]; i != c; i = D[i]) {
      L[R[i]] = L[i];
      R[L[i]] = R[i];
    }
  }
  void restore(int c) {
    for (int i = U[c]; i != c; i = U[i]) {
      L[R[i]] = R[L[i]] = i;
    }
  }

  int check() {
    // memset(vis, 0, sizeof(vis));
    int ret = 0;
    for (int c = R[0]; c != 0; c = R[c]) vis[c] = true;
    for (int c = R[0]; c != 0; c = R[c]) {
      if (vis[c]) {
        ret++;
        vis[c] = false;
        for (int i = D[c]; i != c; i = D[i]) {
          for (int j = R[i]; j != i; j = R[j]) {
            vis[col[j]] = false;
          }
        }
      }
    }
    return ret;
  }
} dlx;

int n, k;
struct City {
  ll x, y;
} c[N];
ll d[N][N];
bool check(ll x) {
  dlx.init(n, n);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (d[i][j] <= x) {
        dlx.link(i, j);
      }
    }
  }
  return dlx.dance(0, k);
}
int main(int args, char const *agrv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  int T;
  scanf("%d", &T);
  int kase = 0;
  while (T--) {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld %lld", &c[i].x, &c[i].y);
    }
    ll mx = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        d[i][j] = abs(c[i].x - c[j].x) + abs(c[i].y - c[j].y);
        mx = max(mx, d[i][j]);
      }
    }

    ll ans = -1;
    ll lb = 0, ub = mx;
    while (lb <= ub) {
      ll mid = (lb + ub) / 2LL;
      if (check(mid)) {
        ans = mid;
        ub = mid - 1;
      } else {
        lb = mid + 1;
      }
    }
    printf("Case #%d: %lld\n", ++kase, ans);
  }
  return 0;
}