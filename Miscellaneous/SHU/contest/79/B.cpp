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
  void work(istream &in, ostream &out) {
    int T;
    in >> T;

    while (T--) {
      int n, k;
      in >> n >> k;

      vector<int> dp[2];
      dp[0].assign(n + 1, 0);
      dp[1].assign(n + 1, 0);
      dp[0][1] = 1, dp[1][1] = 1;

      for (int i = 2; i <= n; ++i) {
        dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
        dp[1][i] = dp[0][i - 1];
      }

      if (k > dp[0][n] + dp[1][n]) {
        out << -1 << "\n";
        continue;
      }

      for (int i = n; i >= 1; --i) {
        if (dp[0][i] >= k) {
          out << 0;
        } else {
          out << 1;
          k -= dp[0][i];
        }
      }
      out << "\n";
    }
    out.flush();
  } 

} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work(cin, cout);
}

