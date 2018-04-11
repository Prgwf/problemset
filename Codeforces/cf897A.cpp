#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 7;

int n, m;
char str[maxn];
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", str + 1);
  for (int i = 0; i  < m; ++i) {
    int l, r;
    char x[2], y[2];
    scanf("%d%d%s%s", &l, &r, x, y);
    for (int j = l; j <= r; ++j) {
      if (str[j] == x[0]) str[j] = y[0];
    }
  }
  printf("%s\n", str + 1);
}
