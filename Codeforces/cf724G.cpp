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

int n, m;
vector<vector<pair<int, ll>>> G;
vector<ll> vloop;
ll vpath[N];
bool vis[N];
ll cnt[64][2];
ll pao2[64];
struct Linear_Basis {
  ll b[64];
  int base, cnt, zero;
  vector<ll> v;

  void init(int base = 62) {
    this->base = base;
    cnt = 0; zero = false;
    memset(b, 0, sizeof(b));
  }
  bool ins(ll x) {
    for (int i = base; i >= 0; --i) {
      if (x >> i & 1LL) {
        if (b[i]) {
          x ^= b[i];
        } else {
          b[i] = x; cnt++;
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

    // zero = n != cnt;

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
void dfs(int x, int p) {
  vis[x] = true;
  for (auto pil : G[x]) {
    int v; ll w;
    tie(v, w) = pil;
    if (v == p) continue;
    if (vis[v]) {
      vloop.push_back(vpath[v] ^ vpath[x] ^ w);
    } else {
      vpath[v] = vpath[x] ^ w;
      dfs(v, x);
    }
  }
  for (int i = 0; i <= 62; ++i) cnt[i][vpath[x] >> i & 1LL]++;
}
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);

  pao2[0] = 1LL;
  for (int i = 1; i <= 62; ++i) {
    pao2[i] = pao2[i - 1] * 2LL % mod;
  }
  scanf("%d %d", &n, &m);
  G.assign(n + 1, vector<pair<int, ll>>());
  for (int i = 0; i < m; ++i) {
    int x, y; ll w;
    scanf("%d %d %lld", &x, &y, &w);
    G[x].emplace_back(y, w);
    G[y].emplace_back(x, w);
  }

  ll ans = 0;
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;

    vloop.clear();
    memset(cnt, 0, sizeof(cnt));
    dfs(i, -1);

    LB.init();
    for (ll x : vloop) LB.ins(x);
    LB.build();
    int r = LB.cnt;
    for (int j = 0; j <= 62; ++j) {
      bool flag = false;
      for (int k = 0; k <= 62; ++k) flag |= (LB.b[k] >> j & 1LL);
      ll t(0);
      if (flag) {
        t += pao2[r - 1] * (cnt[j][0]*(cnt[j][0]-1)/2LL + cnt[j][1]*(cnt[j][1]-1)/2LL) % mod;
        t %= mod;
        t += pao2[r - 1] * (cnt[j][0] * cnt[j][1] % mod);
        t %= mod;
      } else {
        t = pao2[r] * (cnt[j][0] * cnt[j][1] % mod) % mod;
      }
      ans += (t * pao2[j] % mod) % mod;
      ans %= mod;
    }
  }
  printf("%lld\n", ans);
}
