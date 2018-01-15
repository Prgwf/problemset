#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, pos, l, r;
  scanf("%d%d%d%d", &n, &pos, &l, &r);

  if (r - l + 1 == n) {
    puts("0");
    return 0;
  }

  int ans = 0;
  if (l != 1 && r != n) {
    if (pos < l) {
      ans = r - pos;
    } else if (pos > r) {
      ans = pos - l;
    } else {
      ans = r - l + min(r - pos, pos - l);
    }
    ans += 2;
  } else if (l == 1 && r != n) {
    if (pos > r) {
      ans = pos - r;
    } else {
      ans = r - pos;
    }
    ans += 1;
  } else if (l != 1 && r == n) {
    if (pos < l) {
      ans = l - pos;
    } else {
      ans = pos - l;
    }
    ans += 1;
  }
  printf("%d\n", ans);
}

