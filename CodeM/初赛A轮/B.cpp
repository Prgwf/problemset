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
#define lson l,m,o<<1
#define rson m+1,r,o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;

int n, a[N], b[N], d[N];
int main(int args, char const *argv[]) {
#ifdef LOCAL_TEST
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1; i <= n; ++i) scanf("%d", b + i);
  ll ans = 0;
  for (int i = n; i > 1; --i) {
    if (a[i] > b[i]) {
      ll d = a[i] - b[i];
      a[i] = b[i];
      ans += d;
      a[i - 1] += d;
    }
  }
  for (int i = 1; i < n; ++i) {
    if (a[i] > b[i]) {
      ll d = a[i] - b[i];
      a[i] = b[i];
      ans += d;
      a[i + 1] += d;
    }
  }
  printf("%lld\n", ans);
  return 0;
}