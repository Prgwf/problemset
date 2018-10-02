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

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;

struct Linear_Basis
{
    ll b[63], nb[63], tot;

    void init() {
      tot = 0;
      memset(b, 0, sizeof(b));
      memset(nb, 0, sizeof(nb));
    }
    bool insert(ll x) {
      for (int i = 62; i >= 0; --i) {
        if (x >> i & 1LL) {
          if (!b[i]) {
            b[i] = x;
            break;
          }
          x ^= b[i];
        }
      }
      return x > 0;
    }
    ll Max(ll x) {
      ll ret = x;
      for (int i = 62; i >= 0; --i) {
        ret = max(ret, ret ^ b[i]);
      }
      return ret;
    }
    ll Min(ll x) {
      ll ret = x;
      for (int i = 0; i <= 62; ++i) {
        if (b[i]) ret ^= b[i];
      }
      return ret;
    }
    void rebuild() {
      for (int i = 62; i >= 0; --i) {
        for (int j = i - 1; j >= 0; --j) {
          if (b[i] >> j & 1LL) b[i] ^= b[j];
        }
      }
      for (int i = 0; i <= 62; ++i) {
        if (b[i]) nb[tot++] = b[i];
      }
    }
    ll Kth_Max(ll k) {
      ll ret = 0;
      for (int i = 62; i >= 0; --i) {
        if (k >> i & 1LL) ret ^= b[i];
      }
      return ret;
    }
} LB;
struct comp {
  bool operator()(const pair<ll, ll> & x, const pair<ll, ll> &y) const {
    return x.second > y.second;
  }
} ;
int main(int args, char const *argv[]) {
  int n;
  scanf("%d", &n);
  vector<pair<ll, ll> > a;
  for (int i = 0; i < n; ++i) {
    ll x, y;
    scanf("%lld%lld", &x, &y);
    a.push_back({x, y});
  }
  sort(a.begin(), a.end(), comp());
  LB.init();
  ll ans= 0;
  for (int i = 0; i < n; ++i) {
    if (LB.insert(a[i].first)) ans += a[i].second;
  }
  printf("%lld\n", ans);
}
