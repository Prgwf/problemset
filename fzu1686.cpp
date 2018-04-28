#include <iostream>
#include <cstdio>
#include <algorithm>
#include <assert.h>
#include <cstring>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 500 + 20;
const int INF = 0x3f3f3f3f;

struct DXL {
  int n, m, id;
  int U[N*N], D[N*N], L[N*N], R[N*N];
  int row[N*N], col[N*N];
  int S[N], H[N];
  int ansd, ans[N];
  bool vis[N*N];

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

  void dance(int d) {
    if (d + check() >= ansd) return; //false;

    if (R[0] == 0) {
      if (ansd > d) ansd = d;
      return;
    }

    int c = R[0];
    for (int i = R[0]; i != 0; i = R[i]) {
      if (S[i] < S[c]) {
        c = i;
      }
    }
    for (int i = D[c]; i != c; i = D[i]) {
      // ans[d] = row[i];
      remove(i);
      for (int j = R[i]; j != i; j = R[j]) {
        remove(j);
      }
      dance(d + 1);
      for (int j = L[i]; j != i; j = L[j]) {
        restore(j);
      }
      restore(i);
    }
    // return false;
  }

  void remove(int c) {
    for (int i = D[c]; i != c; i = D[i]) {
      L[R[i]] = L[i]; R[L[i]] = R[i];
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

int n, m;
int grid[N][N];
int main() {
  while (scanf("%d %d", &n, &m) != EOF) {
    int cnt = 0;
    memset(grid, 0, sizeof(grid));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        scanf("%d", &grid[i][j]);
        if (grid[i][j]) grid[i][j] = ++cnt;
      }
    }

    dlx.init(n*m, cnt);

    int a, b;
    scanf("%d %d", &a, &b);
    int line = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        for (int x = 0; x < a && i + x <= n; ++x) {
          for (int y = 0; y < b && j + y <= m; ++y) {
            if (grid[i + x][j + y]) dlx.link(line, grid[i + x][j + y]);
          }
        }
        line++;
      }
    }

    dlx.dance(0);
    printf("%d\n", dlx.ansd);
  }
  return 0;
}
