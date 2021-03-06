#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 200 + 20;
const int INF = 0x3f3f3f3f;

int rx[N], ry[N], cx[N], cy[N];
bool mat[N][N];
double dist[N][N];
int n, m, k;

struct DXL {
  int n, m, id;
  int U[N*N], D[N*N], L[N*N], R[N*N];
  int row[N*N], col[N*N];
  int S[N], H[N];
  int ansd, ans[N];
  bool vis[N*N];

  void init(int n, int m) {
    this->n = n; this->m = m;
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
    if (d > limit or d + check() > limit) return false;
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
    memset(vis, 0, sizeof(vis));
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


bool check(double x) {
  memset(mat, 0, sizeof(mat));
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (dist[i][j] <= x) {
        mat[i][j] = 1;
      }
    }
  }

  dlx.init(m, n);
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (mat[i][j]) dlx.link(i, j);
    }
  }
  return dlx.dance(0, k);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    memset(rx, 0, sizeof(rx));
    memset(ry, 0, sizeof(ry));
    memset(cx, 0, sizeof(cx));
    memset(cy, 0, sizeof(cy));

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d %d", cx + i, cy + i);
    }
    for (int i = 1; i <= m; ++i) {
      scanf("%d %d", rx + i, ry + i);
    }
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        dist[i][j] = sqrt(
          (rx[i] - cx[j]) * (rx[i] - cx[j])
          + (ry[i] - cy[j]) * (ry[i] - cy[j])
        );
      }
    }
    double lb = 0, ub = 3e4;
    for (int i = 0; i < 50; ++i) {
      double mid = (lb + ub) / 2.0;
      if (check(mid)) ub = mid;
      else lb = mid;
    }
    printf("%.6f\n", ub);
  }
  return 0;
}
