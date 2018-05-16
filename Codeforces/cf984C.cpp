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

int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    ll p, q, b;
    scanf("%lld %lld %lld", &p, &q, &b);
    if (p == 0LL) {
      printf("Finite\n");
      continue;
    }
    ll g = gcd(p, q);
    p /= g;
    q /= g;
    while (gcd(q, b) != 1) {
      g = gcd(q, b);
      while (q % g == 0) q /= g;
    }
    if (q == 1) printf("%s\n", "Finite");
    else printf("%s\n", "Infinite");
  }
  return 0;
}
