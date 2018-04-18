/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int moder = 1e9 + 7;


int main() {
  int T;
  scanf("%d", &T);

  for (int cas = 1; cas <= T; ++cas) {
    int n;
    scanf("%d", &n);

    int cnt[2][2];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      cnt[x & 1][y & 1]++;
    }

    long long ans = 1LL * n * (n - 1) * (n - 2) / 6LL;
    ans -= 1LL * cnt[0][0] * cnt[0][1] * cnt[1][0];
    ans -= 1LL * cnt[1][1] * cnt[0][1] * cnt[1][0];
    ans -= 1LL * cnt[1][1] * cnt[0][0] * cnt[0][1];
    ans -= 1LL * cnt[1][1] * cnt[0][0] * cnt[1][0];
    printf("Scenario #%d:\n", cas);
    printf("%lld\n", ans);
    puts("");
  }
}
