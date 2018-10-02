#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b, ll mod) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;

int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  ll n, k, p;
  cin >> n >> k >> p;
  ll e, ans;
  if (p == 2) {
    cout << (k > 0 ? 0 : 1);
    return 0;
  }
  e = (((powmod(2, n, p - 1) - n) % (p - 1)) + (p - 1)) % (p - 1);
  ans = powmod(2, e, p);
  if (k == 0) --ans;
  cout << ans;
  return 0;
}
