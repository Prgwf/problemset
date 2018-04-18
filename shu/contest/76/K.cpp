/*
教练我想打ACM~
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 7;

int n;
int w[10000 + 20];
int dp[10000 + 20];
int main() {
  while (~scanf("%d", &n)) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", w + i);
      sum += w[i];
    }

    memset(dp, 0, sizeof(dp));
    int v = sum / 2;
    // printf("v = %d\n", v);
    for (int i = 0; i < n; ++i) {
      for (int j = v; j >= 0; --j) {
        if (j >= w[i]) {
          dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
        }
      }
    }
    int hk = max(dp[v], sum - dp[v]);
    int mwh = sum - hk;
    printf("%d %d\n", mwh, hk);
  }
}
