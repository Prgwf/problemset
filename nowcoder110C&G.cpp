#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<limits.h>
#include<assert.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;

ll a, b, c;
void solve(ll a, ll b, ll c, ll root) {
  // cout << "debug" << a << " " <<  b << " " << c << " " << root << endl;
  
  ll k = 1;
  if (a < 0) {
    a = -a;
    b = -b;
    c = -c;
    k = -k;
  }
  
  ll d1 = gcd(2LL * a, b - root);
  ll d2 = gcd(2LL * a, b + root);
  d1 = abs(d1); d2 = abs(d2);
  ll s = 2LL * a / d1;
  ll t = (b - root) / d1;
  ll u = 2LL * a / d2;
  ll v = (b + root) / d2;

  if (a % (s * u) != 0) {
    cout << k*a << " " << k*b << " " << k*c << endl;
    return;
  }

  ll g = a / (s * u);
  if (s == u) {
    if (t < v) swap(t, v);
  } else if (s < u) {
    swap(s, u); swap(t, v);
  }
  cout << s*g << " " << t*g << " " << k*u << " " << k*v << endl;
}
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  int T;
  cin >> T;
  while (T--) {
    cin >> a >> b >> c;
    // scanf("%lld %lld %lld", &a, &b, &c);
    ll d = b * b - 4 * a * c;
    ll r = floor(sqrt(d));
    if (d < 0 || r * r != d) {
      // printf("%lld %lld %lld\n", a, b, c);
      cout << a << " " << b << " " << c << endl;
      continue;
    }
    solve(a, b, c, r);
  }
  return 0;
}