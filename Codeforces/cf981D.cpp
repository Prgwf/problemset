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

const int N = 100 + 20;
const int INF = 0x3f3f3f3f;

int n, K;
bool dp[N][N];
ll sum[N], ans;
bool gao(ll mask) {
  memset(dp, false, sizeof(dp));
  dp[0][0] = true;

  /*
    [i, j] is the kth seg
  */
  for (int i = 1; i <= n; ++i) {
    for (int k = 1; k <= K; ++k) {
      if (dp[i - 1][k - 1]) for (int j = i; j <= n; ++j) {
        if (((sum[j] - sum[i - 1]) & mask) == mask) {
          dp[j][k] = true;
        }
      }
    }
  }
  return dp[n][K];
}
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  scanf("%d %d", &n, &K);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", sum + i);
    sum[i] += sum[i - 1];
  }
  for (int b = 62; ~b; --b) {
    if (gao(ans | (1LL << b))) {
      ans |= (1LL << b);
    }
  }
  printf("%lld\n", ans);
  return 0;
}