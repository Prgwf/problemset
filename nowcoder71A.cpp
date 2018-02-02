#include <bits/stdc++.h>
using namespace std;

const int N = 1000007;

int n, m;
int a[N];
int num[N], has[N];
int main() {
  scanf("%d", &n);
  int mx = -1;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    num[a[i]]++;
    mx = max(mx, a[i]);
  }
  sort(a, a + n);
  m = unique(a, a + n) - a;

  int ans =0;
  for (int i = 0; i < m; ++i) {
    for (int j = 2; 1LL * j * a[i] <= (long long)mx; ++j) {
      int k = j * a[i];
      if (num[k] || has[k]) {
        ans += num[a[i]];
        has[k] = 1;
        break;
      }
    }
  }
  printf("%d\n", ans);
}