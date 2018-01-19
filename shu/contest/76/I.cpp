/*
教练我想打ACM~
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 7;

int n, q;
int a[maxn];
ll add[maxn];

int main() {
  while (~scanf("%d%d", &n, &q)) {
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    memset(add, 0, sizeof(add));
    for (int i = 0; i < q; ++i) {
      int l, r, val;
      scanf("%d%d%d", &l, &r, &val);
      add[l] += (ll)val;
      add[r + 1] -= (ll)val;
    }
    for (int i = 1; i <= n; ++i) {
      add[i] += add[i - 1];
    }

    for (int i = 1; i <= n; ++i) {
      printf("%lld%c", (ll)a[i] + add[i], i < n ? ' ' : '\n');
    }
  }
}
