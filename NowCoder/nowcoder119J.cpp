#include <bits/stdc++.h>
using namespace std;
#define lson o<<1
#define rson o<<1|1
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100 + 20;
const int INF = 0x3f3f3f3f;

struct DLX {
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
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  int cnt = 0;
  char tch;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> tch;
      grid[i][j] = 0;
      if (tch == '#') {
        grid[i][j] = ++cnt;
      }
    }
  }

  dlx.init(cnt, cnt);
  int dx[] = {-1, 1, 0, 0, 0};
  int dy[] = {0, 0, -1, 1, 0};
  int line = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (grid[i][j]) {
        for (int d = 0; d < 5; ++d) {
          int x = i + dx[d];
          int y = j + dy[d];
          if (x <= 0 || x > n || y <= 0 || y > m) continue;
          if (grid[x][y]) dlx.link(line, grid[x][y]);
        }
        line++;
      }
    }
  }

  dlx.dance(0);
  cout << dlx.ansd << endl;
  return 0;
}
