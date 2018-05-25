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

int solve(int n, int m, int k) {
  if (n == 1) return -1;
  if (n == 2 && m % 2 == 0) return -1;
  if (k % n == 0) k--;
  int ret = m / k;
  if (m % k) ret++;
  if (ret % n == 0) ret++;
  return ret;
}
int main(int args, char const *agrv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    printf("%d\n", solve(n, m, k));
  }
  return 0;
}