#include <cstdio>
#include <cstring>
#include <algorithm>
#include <assert.h>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;

int n;
struct A {
  int l, r;
} a[N];
struct node {
  int l, r, val;
} T[N * 4];
int has[N * 4], ans;
void build(int l, int r, int o = 1) {
  T[o].l = l;
  T[o].r = r;
  T[o].val = 0;

  if (l == r) return;
  int m = (l + r) / 2;
  build(l, m, lson);
  build(m + 1, r, rson);
}
void push_down(int o) {
  if (T[o].val) {
    T[lson].val = T[o].val;
    T[rson].val = T[o].val;
    T[o].val = 0;
  }
}
void update(int l, int r, int val, int o = 1) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].val = val;
    return;
  }
  push_down(o);
  int m = (T[o].l + T[o].r) / 2;
  if (l <= m) update(l, r, val, lson);
  if (r > m) update(l, r, val, rson);
}
void query(int o = 1) {
  if (T[o].val && !has[T[o].val]) ans++;
  has[T[o].val] = 1;
  push_down(o);
  if (T[o].l == T[o].r) return;
  query(lson); query(rson);
}
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);

  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    vector<int> disc;
    for (int i = 1; i <= n; ++i) {
      scanf("%d %d", &a[i].l, &a[i].r);
      disc.push_back(a[i].l);
      disc.push_back(a[i].r);
      disc.push_back(a[i].r + 1);
    }
    sort(disc.begin(), disc.end());
    disc.erase(unique(disc.begin(), disc.end()), disc.end());
    for (int i = 1; i <= n; ++i) {
      a[i].l = lower_bound(disc.begin(), disc.end(), a[i].l) - disc.begin() + 1;
      a[i].r = lower_bound(disc.begin(), disc.end(), a[i].r) - disc.begin() + 1;
    }
    int sz = disc.size();
    build(1, sz);
    for (int i = 1; i <= n; ++i) {
      update(a[i].l, a[i].r, i);
    }
    ans = 0;
    memset(has, 0, sizeof(has));
    query();
    printf("%d\n", ans);
  }
}
