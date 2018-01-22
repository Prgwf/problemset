/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int moder = 1e9 + 7;

int main() {
  int tar = 100003;
  int n, m;
  scanf("%d%d", &n, &m);

  printf("%d %d\n", tar, tar);
  for (int i = 1; i + 1 < n; ++i) {
    printf("%d %d %d\n", i, i + 1, 1);
  }
  printf("%d %d %d\n", n - 1, n, tar - n + 2);

  int left = m - (n - 1);
  for (int t = 2; left; t++) {
    for (int i = 1; left && i  + t <= n; ++i) {
      printf("%d %d %d\n", i, i + t, 100005);
      if (!--left) break;
    }
  }
}
