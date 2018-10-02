#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;

ll a[N], d;
int main() {
  int n;
  scanf("%d%lld", &n, &d);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a + i);
  }

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ll value = a[i] + d;
    int r = upper_bound(a, a + n, value) - a;
    ll k = r - i - 1;
    if (k > 0) {
      ans += k * (k - 1LL) / 2LL;
    }
  }
  printf("%lld\n", ans);
}
