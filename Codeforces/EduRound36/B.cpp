#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, pos, l, r;
  scanf("%d%d%d%d", &n, &pos, &l, &r);

  if (r - l + 1 == n) {
    puts("0");
    return 0;
  }

  if (l == 1) {
    printf("%d\n", abs(r - pos) + 1);
  } else if (r == n) {
    printf("%d\n", abs(l - pos) + 1);
  } else {
    int ans;

    if (pos > l && pos < r) {
      ans = min(2 * (pos - l) + r - pos,
                2 * (r - pos) + pos - l);
    } else if (pos > r) {
      ans = pos - l;
    } else if (pos < l) {
      ans = r - pos;
    }
    printf("%d\n", ans + 2);
  }
}

