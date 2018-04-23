#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {
  ll res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int maxn = 200 + 20;
const int maxr = 200 + 20;
const int maxnode = 2e5 + 20;

struct DLX {
  int U[maxnode], D[maxnode], L[maxnode], R[maxnode];
  int row[maxnode], col[maxnode];
  int S[maxn], H[maxr], ans[maxr], ansd, sz;
  int n, m;

  void init(int n, int m) {
    this->n = n;
    this->m = m;
    for (int i = 0; i <= m; i++) {
      L[i] = i - 1;
      R[i] = i + 1;
      U[i] = D[i] = i;
    }
    L[0] = m;
    R[m] = 0;
    sz = m + 1;
    memset(S, 0, sizeof(S));
    memset(H, -1, sizeof(H));
  }

  void addNode(int r, int c) {
    row[sz] = r;
    col[sz] = c;
    U[sz] = U[c];
    D[sz] = c;
    D[U[sz]] = sz;
    U[D[sz]] = sz;
    if (H[r] == -1) {
      L[sz] = sz;
      R[sz] = sz;
      H[r] = sz;
    } else {
      R[sz] = H[r];
      L[sz] = L[H[r]];
      L[R[sz]] = sz;
      R[L[sz]] = sz;
    }
    S[col[sz]]++;
    sz++;
  }
#define FOR(i, A, s) for (int i = A[s]; i != s; i = A[i])
  void remove(int c) {
    R[L[c]] = R[c];
    L[R[c]] = L[c];
    FOR(i, D, c) FOR(j, R, i) {
      U[D[j]] = U[j];
      D[U[j]] = D[j];
      S[col[j]]--;
    }
  }
  void restore(int c) {
    FOR(i, U, c) FOR(j, L, i) {
      U[D[j]] = j;
      D[U[j]] = j;
      S[col[j]]++;
    }
    R[L[c]] = c;
    L[R[c]] = c;
  }
  bool dfs(int d) {
    if (R[0] == 0) {
      ansd = d;
      return true;
    }
    int c = R[0];
    FOR(i, R, 0) {
      if (S[i] < S[c]) c = i;
    }
    remove(c);
    FOR(i, D, c) {
      ans[d] = row[i];
      FOR(j, R, i) remove(col[j]);
      if (dfs(d + 1)) return true;
      FOR(j, L, i) restore(col[j]);
    }
    restore(c);
    return false;
  }
  bool solve(vector<int> &v) {
    v.clear();
    if (!dfs(0)) return false;
    for (int i = 0; i < ansd; i++) {
      v.push_back(ans[i]);
    }
    return true;
  }
} dlx;
int main(int argc, char const *argv[]) {
  // freopen("data.in", "r", stdin);

  int T;
  scanf("%d", &T);

  while (T--) {
    int n, m;
    scanf("%d %d", &n, &m);

    dlx.init(n, m);

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        int x; scanf("%d", &x);
        if (x) dlx.addNode(i, j);
      }
    }

    vector<int> ans;
    dlx.solve(ans);
    if (ans.size()) {
      cout << "Yes";
    } else {
      cout << "No";
    }
    cout << endl;
  }
  return 0;
}