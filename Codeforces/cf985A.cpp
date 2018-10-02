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

int n;
int a[N];  
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  scanf("%d", &n);
  for (int i = 1; i <= n / 2; ++i) scanf("%d", a + i);
  sort(a + 1, a + 1 + n /2);
  
  int ans = INF, cnt = 0;
  int j = 1;
  for (int i = 1; i <= n /2; ++i) {
    cnt += abs(a[i] - j);
    j += 2;
  }
  ans = min(ans, cnt);
  j = 2;
  cnt = 0;
  for (int i = 1; i <= n / 2; ++i) {
    cnt += abs(a[i] - j);
    j += 2;
  }
  ans = min(ans, cnt);
  printf("%d\n", ans);
  return 0;
}