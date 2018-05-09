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
int main(int args, char const *argv[]) {
  int n;
  scanf("%d", &n);
  LB.init();
  for (int i = 1; i <= n; ++i) {
    ll x; scanf("%lld", &x);
    LB.ins(x);
  }
  printf("%lld\n", LB.Max(0));
}
