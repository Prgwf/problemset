#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;

struct Linear_Basis {
  int base;
  ll b[64], tot;
  bool zero;
  vector<ll> v;

  void init(int base = 62) {
    this->base = base;
    tot = 0; zero = false;
    memset(b, 0, sizeof(b));
  }
  bool ins(ll x) {
    for (int i = base; i >= 0; --i) {
      if (x >> i & 1LL) {
        if (b[i]) {
          x ^= b[i];
        } else {
          b[i] = x;
          for (int k = i - 1; k >= 0; --k) if (b[k] && (b[i] >> k & 1LL)) b[i] ^= b[k];
          for (int k = i + 1; k <= base; ++k) if (b[k] >> i & 1LL) b[k] ^= b[i];
          break;
        }
      }
    }
    return x > 0;
  }
  ll Max(ll x) {
    ll ret = x;
    for (int i = base; i >= 0; --i) {
      ret = max(ret, ret ^ b[i]);
    }
    return ret;
  }
  ll Min(ll x) {
    ll ret = x;
    for (int i = 0; i <= base; ++i) {
      if (b[i]) ret ^= b[i];
    }
    return ret;
  }
  void build() {
    // for (int i = base; i >= 0; --i) {
    //   for (int j = i - 1; j >= 0; --j) {
    //     if (b[i] >> j & 1LL) b[i] ^= b[j];
    //   }
    // }
    v.clear();
    for (int i = 0; i <= base; ++i) {
      if (b[i]) v.push_back(b[i]);
    }
  }
  ll kth(ll k) {
    if (zero) k--;
    if (k >= (1LL << (int)v.size())) return -1;
    ll ret = 0;
    for (int i = 0; i < (int)v.size(); ++i) {
      if (k >> i & 1LL) ret ^= v[i];
    }
    return ret;
  }
} LB;
struct Edge {
  int v;
  ll w;
  int next;
} edge[N * 2];
int head[N], cnt;
void init() {
  memset(head, -1, sizeof(head));
  cnt = 0;
}
void add_edge(int u, int v, ll w) {
  edge[cnt] = {v, w, head[u]};
  head[u] = cnt++;
}
int n, m;
bool vis[N];
ll val[N];
vector<ll> vloop;
void dfs(int x, int p) {
  vis[x] = true;
  for (int i = head[x]; i != -1; i = edge[i].next) {
    Edge & e = edge[i];
    int v = e.v;
    ll w = e.w;
    if (v == p) continue;
    if (vis[v]) {
      vloop.push_back(val[x] ^ val[v] ^ w);
    } else {
      val[v] = val[x] ^ w;
      dfs(v, x);
    }
  }
}
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);

  scanf("%d %d", &n, &m);
  init();
  for (int i = 0; i < m; ++i) {
    int x, y; ll w;
    scanf("%d %d %lld", &x, &y, &w);
    add_edge(x, y, w);
    add_edge(y, x, w);
  }
  dfs(1, -1);
  LB.init();
  for (int i = 0; i < vloop.size(); ++i) {
    LB.ins(vloop[i]);
  }
  printf("%lld\n", LB.Max(val[n]));
}
