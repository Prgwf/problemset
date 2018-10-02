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

int n, a[N];
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    sort(a + 1, a + 1 + n);
    ll ans = 0;
    for (int i= 2; i <= n; ++i) {
      ans += 1LL * (a[1] + a[i]);
    }
    printf("%lld\n", ans);
  }
}
