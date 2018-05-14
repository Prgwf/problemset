#include <cstdio>
#include <algorithm>
#include <assert.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 200000 + 20;
const int mxnode = 3600000 + 20;
const int INF = 0x3f3f3f3f;

int n, m;
struct node {
  int ls, rs, fa, dep;
} T[mxnode];
int sz, root[N];
void build(int l, int r, int &x) {
  if (!x) x = ++sz;
  if (l == r) {
    T[x].fa = l;
    return;
  }
  int m = (l + r) / 2;
  build(l, m, T[x].ls);
  build(m + 1, r, T[x].rs);
}
void update(int l, int r, int &x, int y, int pos, int val) {
  x = ++sz;
  T[x] = T[y];
  if (l == r) {
    T[x].fa = val;
    return;
  }
  int m = (l + r) / 2;
  if (pos <= m) update(l, m, T[x].ls, T[y].ls, pos, val);
  else update(m + 1, r, T[x].rs, T[y].rs, pos, val);
}
void add(int l, int r, int x, int pos) {
  if (pos == l && l == r) {
    T[x].dep++;
    return;
  }
  int m = (l + r) / 2;
  if (pos <= m) add(l, m, T[x].ls, pos);
  else add(m + 1, r, T[x].rs, pos);
}
int query(int l, int r, int x, int pos) {
  if (pos == l && l == r) {
    return x;
  }
  int m = (l + r) / 2;
  if (pos <= m) return query(l, m, T[x].ls, pos);
  else return query(m + 1, r, T[x].rs, pos);
}
int find(int k, int x) {
  int id = query(1, n, k, x);
  if (x == T[id].fa) return id;
  return find(k, T[id].fa);
}
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  scanf("%d %d" , &n, &m);

  build(1, n, root[0]);
  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    int opt, x, y;
    scanf("%d", &opt);
    if (opt == 1) {
      scanf("%d %d", &x, &y);
      x ^= ans; y ^= ans;
      root[i] = root[i - 1];
      int fx = find(root[i], x);
      int fy = find(root[i], y);
      if (fx != fy) {
        if (T[fx].dep > T[fy].dep) swap(fx, fy);
        update(1, n, root[i], root[i - 1], T[fx].fa, T[fy].fa);
        if (T[fx].dep == T[fy].dep) add(1, n, root[i], T[fy].fa);
      }
    }
    if (opt == 2) {
      scanf("%d", &x);
      x ^= ans;
      root[i] = root[x];
    }
    if (opt == 3) {
      scanf("%d %d", &x, &y);
      x ^= ans; y ^= ans;
      root[i] = root[i - 1];
      if (find(root[i], x) == find(root[i], y)) ans = 1;
      else ans = 0;
      printf("%d\n", ans);
    }
  }
}
