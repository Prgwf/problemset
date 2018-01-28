/*
教练我想打ACM~
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 7;

int n;
vector<int> a;
int main() {
  ll po2[32];
  po2[0] = 1;
  for (int i = 1; i < 32; ++i) {
    po2[i] = po2[i - 1] * 2LL;
  }

  while (~scanf("%d", &n)) {
    a.assign(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    ll ans = 0;
    for (int j = 0; j < 32; ++j) {
      int L;
      int l, r;
      l = r = -1;
      for (int i = 0; i <= n; ++i) {
        if (a[i] >> j & 1) {
          if (l < 0) {
            l = i;
            r = i;
          } else {
            r = i;
          }
        } else {
          if (l >= 0 && r >= 0) {
            L = r - l + 1;
            ans += 1LL * po2[j] * L * (L + 1) / 2LL;
          }
          l = r = -1;
        }
      }
    }
    printf("%lld\n", ans);
  }
}
