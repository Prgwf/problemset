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
typedef  long long ll;
const ll mod = 2000000000000000003LL;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;
  
int main(int args, char const *argv[]) {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);

  int T;
  cin >> T;
  while (T--) {
    ll s;
    cin >> s;
    if (s == 1) {
      cout << 1 << endl;
      continue;
    }
    ll b3 = s / 3;
    s -= 3 * b3;
    ll b2 = s / 2;
    s -= 2 * b2;
    if (s) {
      b3--; b2 += 2;
    }
    ll ans = 1;
    while (b3--) {
      ans = ans * 3LL % mod;
    }
    while (b2--) {
      ans = ans * 2LL % mod;
    }
    cout << ans << endl;
  }
  return 0;
}