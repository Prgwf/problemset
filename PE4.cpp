#include <bits/stdc++.h>
using namespace std;

int main() {
  int ans = 0;
  for (int i = 999; i >= 100; --i) {
    for (int j = 999; j >= 100; --j) {
      int x = i * j;
      string s = to_string(x);
      string revs(s.rbegin(), s.rend());
      if (s == revs) ans = max(ans, x);
    }
  }
  printf("%d\n", ans);
}