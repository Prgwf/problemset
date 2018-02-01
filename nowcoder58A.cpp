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
  int n;
  scanf("%d", &n);


  int ans = 0;
  int x = 1, y = n;
  for (int k = 1; ; k ^= 1) {
    if (x >= y) break;

    ans += (x + y) % (n + 1);

    // printf("%d %d ans += %d\n", x, y, (x + y) % (n + 1));

    if (k & 1) x++;
    else y--;
  }

  printf("%d\n", ans);
}
