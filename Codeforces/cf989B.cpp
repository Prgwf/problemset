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

int main(int args, char const *argv[]) {
#ifdef LOCAL_TEST
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  int n, p;
  char a[2005];
  scanf("%d%d%s", &n, &p, a + 1);
  int vaild = false;
  for (int i = 1; i + p <= n; ++i) {
    int j = i + p;
    if (a[i] == '.' || a[j] == '.') {
      vaild = true;
      if (a[i] == a[j]) {
        a[i] = '0';
        a[j] = '1';
      }
      if (a[i] == '.') {
        if (a[j] == '0') a[i] = '1';
        if (a[j] == '1') a[i] = '0';
      }
      if (a[j] == '.') {
        if (a[i] == '0') a[j] = '1';
        if (a[i] == '1') a[j] = '0';
      }
      for (int k = 1; k <= n; ++k) if (a[k] == '.') a[k] = '1';
      break;
    } else if (a[i] != a[j]) {
      vaild = true;
      for (int k = 1; k <= n; ++k) if (a[k] == '.') a[k] = '1';
      break;
    }
  }
  if (vaild) puts(a + 1);
  else puts("No");
  return 0;
}