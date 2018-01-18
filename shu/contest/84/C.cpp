/*
教练我想打ACM~
*/
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

const int maxn = 100000 + 7;

int main() {
  int n, r;
  while (scanf("%d%d", &n, &r) && (n + r)) {
    ll ans = 1;
    for (int i = n; i >= (n - r + 1); --i) {
      ans *= (ll)i;
    }
    printf("%llu\n", ans);
  }
}
