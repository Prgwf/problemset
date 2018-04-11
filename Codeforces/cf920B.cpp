#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int t, n;
struct stu {
  int l, r, id;
} a[N];
int ans[N];
bool cmp (stu x, stu y) {
  if (x.l == y.l) {
    return x.id < y.id;
  }
  return x.l < y.l;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      static int l, r;
      scanf("%d%d", &l, &r);
      a[i] = {l, r, i};
    }
    sort(a, a + n, cmp);

    memset(ans, 0, sizeof(ans));
    int pt = 0;
    for (int i = 0; i < n; ++i) {
      while (pt < a[i].l) ++pt;
      if (a[i].r >= pt) ans[a[i].id] = pt++;
    }
    for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
    printf("\n");
  }
}