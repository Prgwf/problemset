/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int C;
int main() {
  scanf("%d", &C);
  if (C & 1) {
    puts("-1");
  } else {
    int L = C - 2;
    if (L <= 0) {
      puts("-1");
      return 0;
    }
    printf("%d\n", 4);
    printf("%d %d\n", 0, 0);
    printf("%d %d\n", 1, 0);
    printf("%d %d\n", 1, L / 2);
    printf("%d %d\n", 0, L / 2);
  }
}
