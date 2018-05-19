#include <bits/stdc++.h>
using namespace std;

const int N = 345;
const int mod = 1e9 + 7;
int n, k;
vector<vector<int>> T;
long long dp[N][N];
int main() {
  scanf("%d%d", &n, &k);
  T.resize(n);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
  }
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] * (k - j + 1)) % mod;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= k; ++i) (ans += dp[n][i]) %= mod;
  printf("%lld\n", ans);
  return 0;
}