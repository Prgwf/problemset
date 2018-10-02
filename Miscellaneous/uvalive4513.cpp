#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int N = 40000 + 10;
const ull x = 131;
int n, m, pos;
ull hs[N], H[N], xp[N];
int rnk[N];
int cmp(const int &a, const int & b) {
  return hs[a] < hs[b] || (hs[a] == hs[b] && a < b);
}

int possible(int L) {
  int c = 0;
  pos = -1;
  for (int i = 0; i < n - L + 1; ++i) {
    rnk[i] = i;
    hs[i] = H[i] - H[i + L] * xp[L];
  }
  sort(rnk, rnk + n - L + 1, cmp);
  for (int i = 0; i < n - L + 1; ++i) {
    if (i == 0  || hs[rnk[i]] != hs[rnk[i - 1]]) c = 0;
    if (++c >= m) pos = max(pos, rnk[i]);
  }
  return pos >= 0;
}

int main() {
  char s[N];
  while (scanf("%d", &m) != EOF && m) {
    scanf("%s", s);
    n = strlen(s);

    H[n] = 0;
    for (int i = n - 1; i >= 0; --i) H[i] = H[i + 1] * x + (s[i] - 'a');
    xp[0] = 1;
    for (int i = 1; i <= n; ++i) xp[i] = xp[i - 1] * x;
    if (!possible(1)) printf("none\n");
    else {
      int L = 1, R = n, ans;
      while (L <= R) {
        int mid = (L + R) / 2;
          if (possible(mid)) {
            ans = mid; L = mid + 1;
          } else {
            R = mid - 1;
          }
      }
      possible(ans);
      printf("%d %d\n", ans, pos);
    }
  }
  return 0;
}