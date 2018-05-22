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

const int N = 1000000 + 20;
const int INF = 0x3f3f3f3f;

int n, m, k, l;
int a[N];
map<int, int> pos;
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  scanf("%d %d %d", &n, &k, &l);
  m = n * k;
  for (int i = 1; i <= m; ++i) {
    scanf("%d", a + i);
  }
  sort(a + 1, a + 1 + m);
  int v = min(a[m], a[1] + l);
  int L = 1, R =1;
  for (int  i = 1; i <= m; ++i) {
    if (a[i] <= v) R = i;
  }
  // assert(R - L + 1 >= n);
  if (R < n) {
    printf("%d\n", 0);
    return 0;
  }
  int more = R - n, i = 1, t = 0;
  // printf("%d, R =%d\n", more, R);
  ll ans = 0;
  while (more) {
    // printf("%d, a[%d]=%d\n", more, i, a[i]);
    ans += 1LL * a[i++]; t++;
    for (int cnt = 1; more && i <= m && cnt < k; ++i, ++cnt) more--;
  }
  // printf("%d, %d %lld\n", i, t, ans);
  if (t < n) {
    while (t < n) {
      // assert(i <= n);
      if (i > R) {
        printf("0\n");
        return 0;
      }
      ans += 1LL * a[i];
      i++; t++;
    }
  }
  printf("%lld\n", ans);
  return 0;
}