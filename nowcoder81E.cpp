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
          // for (int k = i - 1; k >= 0; --k) if (b[k] && (b[i] >> k & 1LL)) b[i] ^= b[k];
          // for (int k = i + 1; k <= base; ++k) if (b[k] >> i & 1LL) b[k] ^= b[i];
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
} LB[N];
int fa[N], val[N], pos[N];
int ans[N];
bool used[N];
int find(int x) {
  if (x == fa[x]) return x;
  fa[x] = find(fa[x]);
  return fa[x];
}
ll unite(int x, int y) {
  int fx = find(x);
  int fy = find(y);
  if (fx == fy)  return LB[fx].Max(0);

  fa[fy] = fx;
  for (int i = 0; i < 63; ++i) {
    LB[fx].ins(LB[fy].b[i]);
  }
  return LB[fx].Max(0);
}
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);

  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d",  val + i);
  }

  for (int i = 1; i <= n; ++i) {
    scanf("%d", pos + i);
    fa[i] = i;
    LB[i].init();
    LB[i].ins(val[i]);
  }

  memset(used, false, sizeof(used));
  ans[n] = val[pos[n]];
  used[pos[n]] = true;
  int mx = ans[n];
  for (int i = n - 1; i >= 1; --i) {
    if (used[pos[i] + 1]) unite(pos[i], pos[i] + 1);
    if (used[pos[i] - 1]) unite(pos[i], pos[i] - 1);
    mx = max((ll)(mx), LB[pos[i]].Max(0));
    used[pos[i]] = true;
    ans[i] = mx;
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d\n", ans[i]);
  }
}
