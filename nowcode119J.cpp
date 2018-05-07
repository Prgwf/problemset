#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 1000 + 20;
const int INF = 0x3f3f3f3f;

char s[N];
ll w[N], dp[N][N];
int main(int args, char const *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d%s", &n, s + 1);
    assert(n == (int)strlen(s + 1));
    for (int i = 1; i <= n; ++i) scanf("%lld", w + i);

  }
}
