#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 5000 + 20;
const int INF = 0x3f3f3f3f;

int n;
int a[N], dp[N][N];
int ans[N][N];
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    ans[i][1] = dp[i][1] = a[i];
  }
  for (int k = 2; k <= n; ++k) {
    for (int i = 1; i + k - 1<= n; ++i) {
      dp[i][k] = dp[i][k - 1] ^ dp[i + 1][k - 1];
      ans[i][k] = max(dp[i][k], max(ans[i][k - 1], ans[i + 1][k - 1]));
    }
  }
  for (int i = 1; i <= n; ++i) ans[i][1] = dp[i][1];
  int l, r, q;
  scanf("%d", &q);
  for (int i = 0;  i < q; ++i) {
    scanf("%d %d", &l, &r);
    printf("%d\n", ans[l][r - l + 1]);
  }
  return 0;
}
