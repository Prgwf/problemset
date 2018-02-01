/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int moder = 1e9 + 7;

char s[maxn];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  scanf("%s", s);

  for (int i = 0; i < m; ++i) {
    int l, r;
    char from[2], to[2];
    scanf("%d%d%s%s", &l, &r, from, to);
    --l; --r;
    for (int j = l; j <= r; ++j) {
      if (s[j] == from[0]) {
        s[j] = to[0];
      }
    }
  }

  puts(s);
}
