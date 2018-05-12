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

int n;
ll a[N], p, s;
bool check(ll x) {
  ll c = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > x) {
      c += a[i] - x;
    } else {
      break;
    }
  }
  return c * p <= s;
}
int main(int args, char const *argv[]) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a + i);
  }
  scanf("%lld%lld", &p, &s);
  sort(a, a + n, greater<ll>());

  ll ans = -1;
  ll lb = 1, ub = 20000;
  while (lb <= ub) {
    ll mid = (lb + ub) / 2LL;
    if (check(mid)) {
      ans = mid;
      ub = mid - 1LL;
    } else {
      lb = mid + 1LL;
    }
  }
  printf("%lld\n", ans);
}
