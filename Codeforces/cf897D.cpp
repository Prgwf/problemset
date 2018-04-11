#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int N = 100000 + 7;

int n, m, c;
int a[N];
int main() {
  scanf("%d %d %d", &n, &m, &c);

  for (int _ = 0; _ < m; ++_) {
    int x;
    scanf("%d", &x);

    if (x * 2 <= c) {
      for (int i = 1; i <= n; ++i) {
        if (a[i] > x || a[i] == 0) {
          a[i] = x;
          printf("%d\n", i);
          fflush(stdout);
          break;
        }
      }
    } else {
      for (int i = n; i >= 1; --i) {
        if (a[i] < x || a[i] == 0) {
          a[i] = x;
          printf("%d\n", i);
          fflush(stdout);
          break;
        }
      }
    }
  }
}
