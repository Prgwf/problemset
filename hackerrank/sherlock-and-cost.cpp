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
  int dp[2][maxn];
  void work(istream &in, ostream &out) {
    int T;
    in >> T;
    
    while (T--) {
      int n;
      in >> n;
      vector<int> b;
      b.resize(n);
      
      for (int i = 0; i < n; ++i) {
        in >> b[i];
      }

      /*
       * 状态表示：dp[k][i] 第i位为止，产生的最大差贡献
       * 转移: dp[0][i] = max(dp[0][i - 1] + abs(1 - 1), dp[1][i - 1] + abs(b[i - 1] - 1))
       *       dp[1][i] = max(dp[0][i - 1] + abs(1 - b[i]), dp[1][i - 1] +
       *       abs(b[i - 1] - b[i]))
       * */
      memset(dp, 0, sizeof(dp));
      for (int i = 1; i < n; ++i) {
        dp[0][i] = max(dp[0][i - 1] + 0, dp[1][i - 1] + b[i  - 1] - 1);
        dp[1][i] = max(dp[0][i - 1] + b[i] - 1, dp[1][i - 1] + abs(b[i  - 1] - b[i]));
      }

      out << max(dp[0][n - 1], dp[1][n - 1]) << endl;
    }
  } 
} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work(cin, cout);
}

