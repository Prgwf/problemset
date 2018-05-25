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

const int N = 5000 + 20;
const int INF = 0x3f3f3f3f;

ll f[N];
ll inv(ll x) {return powmod(x, mod - 2);}
int main(int args, char const *agrv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  
  f[1] = 1LL;
  for (ll i = 2; i <= 2000; ++i) f[i] = i * f[i - 1] % mod;
  
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll ans = f[a + b + c + d];
  ans = (ans * inv(f[a])) % mod;
  ans = (ans * inv(f[b])) % mod;
  ans = (ans * inv(f[c])) % mod;
  ans = (ans * inv(f[d])) % mod;
  cout << ans;
  return 0;
}