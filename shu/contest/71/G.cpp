/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int moder = 1e9 + 7;

struct Solution {
  int a[11][16];
  int dp[11][16];
  int route[11][16];
  int ans[11];
  void work(istream &in, ostream &out) {
    int n, m;
    in >> n >> m;

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        in >> a[i][j];
      }
    }

    /*
     * 状态表示：dp[i][j] 表示前i个公司分了j个机器时的最大收益
     * 转移： dp[i][j] = dp[i - 1][j - k] + a[i][k]
     * */
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        for (int k = 0; k <= j; ++k) {
          int t = dp[i - 1][j - k] + a[i][k];
          if (dp[i][j] <= t) {
            dp[i][j] = t;
            route[i][j] = k;
          }
        }
      }
    }
    
    out << dp[n][m] << endl;

    memset(ans, 0, sizeof(ans));
    int i = n, k = m;
    do {
      ans[i] = route[i][k];
      k -= route[i][k];
      --i;
    } while (i);
    for (int i = 1; i <= n; ++i) {
      cout << i << " " << ans[i] << "\n";
    }
  } 

} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work(cin, cout);
}

