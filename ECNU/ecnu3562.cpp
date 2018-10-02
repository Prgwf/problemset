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

const int N = 1000000 + 20;
const int INF = 0x3f3f3f3f;

int n;
int id = 0;
int par[N], root[N];
struct node {
  int l, r;
  int ans;
} a[N * 40];
void update(int l, int r, int & x, int y, int pos, int val) {
  x = ++id;
  a[x] = a[y];
  if (l == r) {
    a[x].ans = val;
    return;
  }
  int m = (l + r) / 2;
  if (pos <= m) update(l, m, a[x].l, a[y].l, pos, val);
  else update(m + 1, r, a[x].r, a[y].r, pos, val);
}
int query(int l, int r, int x, int pos) {
  if (x == 0) return -1;
  if (l == r) {
    return a[x].ans;
  }
  int m = (l + r) / 2;
  if (pos <= m) return query(l, m, a[x].l, pos);
  else return query(m + 1, r, a[x].r, pos);
}
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  scanf("%d", &n);
  for (int i = 2; i <= n; ++i)  scanf("%d", par + i);
  for (int i = 1; i <= n; ++i) {
    root[i] = root[par[i]];
    int t;
    scanf("%d", &t);
    for (int j = 0; j < t; ++j) {
      int x;
      scanf("%d", &x);
      update(1, 1000000, root[i], root[i], x, i);
    }
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int v, f;
    scanf("%d %d", &v, &f);
    printf("%d\n", query(1, 1000000, root[v], f));
  }
  return 0;
}
