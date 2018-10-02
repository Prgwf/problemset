/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 200 + 20;
const int moder = 1e9 + 7;

struct Solution {
  char x[maxn];
  char y[maxn];
  int dp[maxn][maxn];
  void work(istream &in, ostream &out) {
    scanf("%s", x + 1);
    scanf("%s", y + 1);
    
    int n = strlen(x + 1);
    int m = strlen(y + 1);

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (x[i] == y[j]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    printf("%d\n", dp[n][m]);
  } 

} ; 
Solution Woo;
int main() {
  // ios_base::sync_with_stdio(0);
  // cin.tie(0); cout.tie(0);
  Woo.work(cin, cout);
}

