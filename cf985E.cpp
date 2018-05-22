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

int tr[N], top;
void inc(int x) {
  for (; x <= top; x += x & (-x)) tr[x]++;
}
int sum(int x) {
  int ret = 0; 
  for (; x; x -= x & (-x)) ret += tr[x];
  return ret;
}  
int n, k, d;
int a[N], dp[N];
int main(int args, char const *argv[]) {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);

  scanf("%d %d %d" ,&n, &k, &d);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  sort(a + 1, a + 1 + n);
  top = n + 1;
  dp[0] = 1; inc(1);
  for (int i = 1; i <= n; ++i) {
    int l = lower_bound(a + 1, a + 1 + n, a[i] - d) - a;
    int r = i - k + 1;
    if (l > r) continue;
    if (sum(r) - sum(l - 1) > 0) {
      dp[i] = 1; inc(i + 1);
    }
  }
  printf("%s\n", dp[n] ? "YES":"NO");
  return 0;
}