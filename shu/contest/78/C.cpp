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
  ll a[maxn];
  void work() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
      int l, r, c;
      scanf("%d%d%d", &l, &r, &c);

      a[l] += 1LL * c;
      a[r + 1] -= 1LL * c;

    }
    for (int i = 1; i <= n; ++i) {
      a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
      printf("%lld%c", a[i], i < n ? ' ': '\n');
    }
  }

} ; 
Solution Woo;
int main() {
  Woo.work();
}

