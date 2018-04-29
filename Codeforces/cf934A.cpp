#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 123;
int n, m;
int a[N];
int b[N];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < m; ++i) scanf("%d", &b[i]);

  ll ans = 2e18;
  for (int i =  0; i < n; ++i) {
    ll tmp = -2e18;
    for (int j = 0; j < n; ++j) if (j != i) {
      for (int k = 0; k < m; ++k) {
        tmp = max(tmp, 1LL * a[j] * b[k]);    
      }
    }
    ans = min(ans, tmp);
  }
  printf("%lld\n", ans);
}   