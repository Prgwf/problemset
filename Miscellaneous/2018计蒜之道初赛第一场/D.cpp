#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 3200000 + 20;
const int INF = 0x3f3f3f3f;

struct node {
  int l, r, val;
} a[N];
int id = 0, nid[100005], root;
int n, m;
int st[N], top, color[N], dfn[N], low[N], dfsnum, cnt;
struct Edge {int u, v, next;} e[N * 3];
int tot, head[N];
int odeg[N];
ll cost[N];
void add_edge(int x, int y) {
  e[++tot] = {x, y, head[x]};
  head[x] = tot;
}
void tarjan(int x) {
  dfn[x] = low[x] = ++dfsnum;
  st[++top] = x;
  for (int i = head[x]; i != 0; i = e[i].next) {
    if (!dfn[e[i].v]) {
      tarjan(e[i].v);
      low[x] = min(low[x], low[e[i].v]);
    } else if (!color[e[i].v]) {
      low[x] = min(low[x], dfn[e[i].v]);
    }
  }
  if (dfn[x] == low[x]) {
    ++cnt;
    while (st[top] != x) color[st[top--]] = cnt;
    color[st[top--]] = cnt;
  }
}
void update(int l, int r, int &x, int y, int pos, int val) {
  x = ++id;
  a[x] = a[y];
  if (l == r) {
    a[x].val = val;
    nid[pos] = id;
    return;
  }
  int m = (l + r) / 2;
  if (pos <= m) update(l, m, a[x].l, a[y].l, pos, val);
  else update(m + 1, r, a[x].r, a[y].r, pos, val);
  if (a[x].l) add_edge(x, a[x].l);
  if (a[x].r) add_edge(x, a[x].r);
}
void query(int ql, int qr, int l, int r, int x, int y) {
  if (ql > r || qr < l) return;
  if (ql <= l && r <= qr) {
    add_edge(x, y);
    return;
  }
  int m = (l + r) / 2;
  if (ql <= m) query(ql, qr, l, m, x, a[y].l);
  if (qr > m) query(ql, qr, m + 1, r, x, a[y].r);
}
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    static int x;
    scanf("%d", &x);
    update(1, n, root, root, i, x);
  }
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    static int opt;
    scanf("%d", &opt);
    static int x, y, z;
    if (opt) {
      scanf("%d %d %d", &z, &x, &y);
      query(x, y, 1, n, nid[z], root);
    } else {
      scanf("%d %d", &x, &y);
      update(1, n, root, root, x, y);
    }
  }

  for (int i = 1; i <= id; ++i) {
    if (!dfn[i]) tarjan(i);
  }
  for (int i = 1; i <= id; ++i) {
    cost[color[i]] += a[i].val;
  }
  for (int i = 1; i <= tot; ++i) {
    if (color[e[i].u] != color[e[i].v]) {
      odeg[color[e[i].u]]++;
    }
  }
  ll ans = 4e18;
  for(int i = 1; i <= cnt; ++i) {
    // printf("cost[%d]=%lld\n", i, cost[i]);
    if (odeg[i] == 0) {
      ans = min(ans, cost[i]);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
