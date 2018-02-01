#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 20;

int n;
int a[maxn];
int L[maxn], R[maxn];
int T[maxn];
pair<int, int> pii[maxn];
void add(int x, int k) {
  while (x < n) {
    T[x] += k;
    x += x & -x;
  }
}

ll sum(int x) {
  ll ret = 0;
  while (x) {
    ret += T[x];
    x -= x & -x;
  }
  return ret;
}

void init() {
  for (int i = 1; i <= n; ++i) {
    L[i] = R[i] = i;
  }
  for (int i = n - 1; i >= 1; --i) {
    int now = i;
    while (now + 1 <= n && a[i] <= a[now + 1]) now = R[now + 1];
    R[i] = now;
  }
  for (int i = 1; i <= n; ++i) {
    R[i]++;
  }

  for (int i = 2; i <= n; ++i) {
    int now = i;
    while (now - 1 >= 1 && a[i] >= a[now - 1]) now = L[now - 1];
    L[i] = now;
  }
  for (int i = 1; i <= n; ++i) {
    L[i]--;
  }
}

int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }

    init();
    for (int i = 1; i <= n; ++i) {
      pii[i] = {R[i], i};
    }
    sort(pii + 1, pii + 1 + n, less<pair<int, int>>());
    long long ans = 0;
    int pt = 1;
    for (int i = 1; i <= n; ++i) {
      while (pt <= n && pii[pt].first <= i) {
        add(pii[pt].second, 1);
        ++pt;
      }
      ans += sum(L[i]);
    }
    printf("%lld\n", ans + 1);
  }
}
