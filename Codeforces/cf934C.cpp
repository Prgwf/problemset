#include <bits/stdc++.h>
using namespace std;

const int N = 2345;
int n;
int a[N];
int dp[N][N][3][3];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  
  for (int i = 1; i <= n; ++i) {
    dp[i][i][1][1] = (a[i] == 1);
    dp[i][i][1][2] = 1;
    dp[i][i][2][1] = 1;
    dp[i][i][2][2] = (a[i] == 2);
    for (int j = i + 1; j <= n; ++j) {
      dp[i][j][1][1] = dp[i][j - 1][1][1] + (a[j] == 1);
      dp[i][j][1][2] = max(dp[i][j - 1][1][1] + 1, dp[i][j - 1][1][2] + (a[j] == 2));
      dp[i][j][2][1] = max(dp[i][j - 1][2][2] + 1, dp[i][j - 1][2][1] + (a[j] == 1));
      dp[i][j][2][2] = dp[i][j - 1][2][2] + (a[j] == 2);  
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      ans = max(ans, 
                    dp[1][i - 1][1][1] + max(dp[i][j][1][2], dp[i][j][2][2]) + max(dp[j + 1][n][1][1], dp[j + 1][n][1][2]));
      
      ans = max(ans, 
                    max(dp[1][i - 1][1][1], dp[1][i - 1][1][2]) + dp[i][j][1][1] + dp[j + 1][n][2][2]);
      
      ans = max(ans, 
                    dp[1][i - 1][1][1] + dp[i][j][2][1] + dp[j + 1][n][2][2]);
    }
  }

  printf("%d\n", ans);
}
