#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
#if defined(_WIN32)
#define lld I64d
#endif

const int N = 1000 + 20;
const int maxnnode = 5e5 + 20;
const int INF = 0x3f3f3f3f;

struct DLX {
  int n, m, id;
  int U[maxnnode], D[maxnnode], L[maxnnode], R[maxnnode];
  int row[maxnnode], col[maxnnode];
  int S[N], H[N];
  int ansd, ans[N];

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
    id++;
    S[c]++;
    col[id] = c;
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
  void dance(int d) {
    if (ansd != -1 && ansd <= d) return;
    if (R[0] == 0) {
      if (ansd == -1 || ansd > d) ansd = d;
      return;
    }
    int c = R[0];
    for (int i = R[0]; i != 0; i = R[i]) {
      if (S[i] < S[c]) c = i;
    }
    remove(c);
    for (int i = D[c]; i != c; i = D[i]) {
      ans[d] = row[i];
      for (int j = R[i]; j != i; j = R[j]) remove(col[j]);
      dance(d + 1);
      for (int j = L[i]; j != i; j = L[j]) restore(col[j]);
    }
    restore(c);
  }
  void remove(int c) {
    L[R[c]] = L[c];
    R[L[c]] = R[c];
    for (int i = D[c]; i != c; i = D[i]) {
      for (int j = R[i]; j != i; j = R[j]) {
        U[D[j]] = U[j];
        D[U[j]] = D[j];
        --S[col[j]];
      }
    }
  }
  void restore(int c) {
    for (int i = U[c]; i != c; i = U[i]) {
      for (int j = L[i]; j != i; j = L[j]) {
        U[D[j]] = j;
        D[U[j]] = j;
        S[col[j]]++;
      }
    }
    L[R[c]] = R[L[c]] = c;
  }
} dlx;

int n, m, p;
int grid[N][N];
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d %d", &n, &m, &p);
    int id = 0;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) grid[i][j] = ++id;
    dlx.init(p, n*m);
    for (int k = 1; k <= p; ++k) {
      int x1, y1, x2, y2;
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      for (int i = x1 + 1; i <= x2; ++i) {
        for (int j = y1 + 1; j <= y2; ++j) {
          dlx.link(k, grid[i][j]);
        }
      }
    }

    int & ans = (dlx.ansd = -1);
    dlx.dance(0);
    printf("%d\n", ans);
  }
  return 0;
}
