#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;

int n, T;
int a[N], c[N];
int dp[N][305];
pair<int, int> s[N];
struct comp {
  bool operator () (const pair<int, int> &x, const pair<int, int> &y) const {
    return x.first * y.second > y.first * x.second;
  }
} ;
int main(int args, char const *argv[]) {
  scanf("%d %d", &n, &T);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", a + i, c + i);
    s[i] = {a[i], c[i]};
  }
  sort(s + 1, s + 1 + n, comp());
  for (int i = 1; i <= n; ++i) {
    tie(a[i], c[i]) = s[i];
  }

  memset(dp, 0, sizeof(dp));
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int t = T; t >= 0; --t) {
      if (t >= c[i]) {
        dp[i][t] = max(dp[i - 1][t], dp[i - 1][t - c[i]] + (a[i] * (T - t)));
        ans = max(dp[i][t], ans);
      }
    }
  }
  printf("%d\n", ans);
}
