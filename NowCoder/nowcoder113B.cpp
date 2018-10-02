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

const int N = 500000 + 20;
const int INF = 0x3f3f3f3f;

int n, m;
int a[N];
ll sum[N];
int main(int args, char const *agrv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i); 
    a[i] = -a[i];
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d", a + i + n);
  }
  sort(a + 1, a + 1 + n + m);
  ll ans =  0;
  for (int i = 1; i <= n + m; ++i) ans += abs(a[i]);
  a[0] = a[n+m+1] = 0;
  int pos = (n + m + 1) / 2;
  ll ret = abs(a[pos]);
  for (int i = 1; i <= n + m; ++i) {
    ret += abs(a[i] + (0 - a[pos]));
  }
  ans = min(ans, ret);
  
  pos = (n + m + 1) / 2 - 1;
  ret = abs(a[pos]);
  for (int i = 1; i <= n + m; ++i) {
    ret += abs(a[i] + (0 - a[pos]));
  }
  ans = min(ans, ret);

  pos = (n + m + 1) / 2 + 1;
  ret = abs(a[pos]);
  for (int i = 1; i <= n + m; ++i) {
    ret += abs(a[i] + (0 - a[pos]));
  }
  ans = min(ans, ret);  
  printf("%lld\n", ans);
  return 0;
}