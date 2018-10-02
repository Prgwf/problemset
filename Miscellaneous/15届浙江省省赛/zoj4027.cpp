#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll w, ll b) {ll res=1;w%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*w%mod;w=w*w%mod;}return res;}
ll gcd(ll w, ll b) { return b ? gcd(b, w % b) : w; }
#if defined(_WIN32)
#define lld I64d
#endif


const int N = 1000 + 20;
const ll INF = 4e12;

int n;
char s[N];
ll w[N], dp[N][N], val[N][N], sum[N];
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);

  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%s", &n, s + 1);
    assert(n <= 1000);
    for (int i = 1; i <= n; ++i)  scanf("%lld", w + i);
    // work
    int rig = 0;
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; ++i) {
      if (s[i] == ')') sum[++rig] = w[i];
    }
    for (int i = rig - 1; i >= 0; --i) {
      sum[i] += sum[i + 1];
    }

    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= rig + 1; ++j) {
        dp[i][j] = -INF;
        val[i][j] = -INF;
      }
    }
    memset(val[0], 0, sizeof(val[0]));

    int l(0), r(0);
    ll ans = 0;
    for (int i = n; i; --i) {
      if (s[i] == '(') {
        l++;

        for (int k = rig; k >= rig - r; --k) {
          dp[l][k] = val[l - 1][k] + w[i] * (sum[rig - r + 1] - sum[k + 1]);
          ans = max(ans, dp[l][k]);
        }
        for (int k = rig; k >= 1; --k) {
          val[l][k] = max(val[l][k + 1], dp[l][k]);
        }
        continue;
      }

      if (s[i] == ')') {
        r++;
        continue;
      }
    }
    printf("%lld\n", ans);
  }
}
