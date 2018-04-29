#include <bits/stdc++.h>
using namespace std;

int main() {
  int k, up = 2 * 18;
  scanf("%d", &k);
  if (k > up) {
    puts("-1");
    return 0;
  }
  if (k & 1) printf("6");
  k /= 2;
  while (k--) printf("8");
  puts("");
}