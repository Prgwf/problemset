#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 200000 + 20;
const int INF = 0x3f3f3f3f;

int n;
ll a[N], sum[N];
map<ll, ll> cnt;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
    sum[i] = sum[i - 1] + a[i];
  }
  for (int i = 0; i <= n; ++i) {
    cnt[sum[i]]++;
  }
  ll ans = 0;
  for (const auto & kv : cnt) {
    if (kv.second > 1) {
      ll x = kv.second;
      ans += x * (x - 1) / 2LL;
    }
  }
  printf("%lld\n", ans);
}
