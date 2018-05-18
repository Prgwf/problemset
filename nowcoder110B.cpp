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

int x[N], y[N];
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", x + i, y + i);
  }
  int cc = 0, c = 0;
  for (int i = 0; i < n; ++i) {
    int abx = x[(i+1)%n] - x[i];
    int aby = y[(i+1)%n] - y[i];
    int acx = x[(i+2)%n] - x[i];
    int acy = y[(i+2)%n] - y[i];
    int d = abx*acy - aby*acx;
    if (d > 0) cc++; else c++;
  }
  assert(cc != c);
  printf("%s\n", cc >= c ? "counterclockwise":"clockwise");
  return 0;
}