/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int moder = 1e9 + 7;


int check(int x) {
  while (x) {
    int t = x  % 10;
    if (t == 7) return true;
    x /= 10;
  }
  return false;
}

int main() {
  int x;
  scanf("%d", &x);
  int hh, mm;
  scanf("%d%d", &hh, &mm);

  int ans = inf;
  for (int i = 0; i < 24; ++i) {
    for (int j = 0; j < 60; ++j) {
      if (!check(i) && !check(j)) continue;
      int h = i, m = j;
      int cnt = 0;
      while (!(h == hh && m == mm)) {
        ++cnt;
        m += x;
        if (m >= 60) {
          m %= 60;
          h++;
          if (h >= 24) {
            h %= 24;
          }
        }
        if (cnt > 50000) break;
      }
      ans = min(ans, cnt);
    }
  }
  printf("%d\n", ans);
}
