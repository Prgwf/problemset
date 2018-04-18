#include <bits/stdc++.h>
using namespace std;
  
typedef unsigned long long ull;
const int N = 50000 * 2 + 5;
int n, m, k;
int a[N];
int ans[N];
vector<int> pos[N];
ull sd, hs[N], sdp[N];
  
bool check(int x, int y, int L) {
  if (L == 0) return 1;
  ull u = hs[x] - hs[x + L] * sdp[L];
  ull v = hs[y] - hs[y + L] * sdp[L];
  return u == v;
}
// ok(x, y, l) : substr(x, l) > substr(y, l) ?
bool ok(int x, int y, int t) {
  int lb = 0, ub = n, ret = -1;
  while (lb <= ub) {
    int mid = (lb + ub) / 2;
    if (check(x, y, mid)) {
      ret = mid; lb = mid + 1;
    } else {
      ub = mid - 1;           
    }
  }
  if (ret == n) return 0;
  return ((a[x + ret] + t) % m) < ((a[y + ret] + t) % m);
}
  
int main() {
  scanf("%d%d%d", &n, &m, &k);
  
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    a[n + i] = a[i];
    pos[(m - a[i]) % m].push_back(i);
  }
  
  sd = 19260817; sdp[0] = 1;
  for (int i = 1; i < N; ++i) {
    sdp[i] = sdp[i - 1] * sd;
  }
  hs[2 * n] = 0;
  for (int i = 2 * n - 1; ~i; --i) {
    hs[i] = hs[i + 1] * sd + a[i];
  }
  
  int x = 0;
  for (int i = 0; i < n; ++i) {
    if (ok(i, x, 0)) x = i;
  }
  ans[0] = a[x + k - 1];
  for (int i = 1; i < m; ++i) {
    if (pos[i].empty()) {
      ans[i] = ans[i - 1] + 1;
      continue;
    }
    x = pos[i][0];
    for (int j = 1; j < (int)pos[i].size(); ++j) {
      if (ok(pos[i][j], x, i)) x = pos[i][j];
    }
    ans[i] = (a[x + k - 1] + i) % m;
  }
  
  for (int i = 0; i < m; ++i) {
    printf("%d\n", ans[i]);
  }
}