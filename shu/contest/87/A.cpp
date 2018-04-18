/*
教练我想打ACM~
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 7;

int main() {
  int k;
  while (scanf("%d", &k) != EOF) {
    ++k;
    if (k & 1) {
      printf("%d\n", 1);
    } else {
      printf("%d\n", 0);
    }
  }
}
