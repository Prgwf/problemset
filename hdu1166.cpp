#include <bits/stdc++.h>
using namespace std;

const int maxn = 500000 + 7;
int n;
int block, num, belong[maxn], l[maxn], r[maxn];
int a[maxn];
int sum[maxn];
void build() {
  block = sqrt(n);
  num = n / block;
  if (n % block) num++;

  for (int i = 1; i <= num; ++i) {
    l[i] = (i - 1) * block + 1;
    r[i] = i * block;
  }
  r[num] = n;

  for (int i = 1; i <= n; ++i) {
    belong[i] = (i - 1) / block + 1;
  }

  for (int i = 1; i <= num; ++i) {
    for (int j = l[i]; j <= r[i]; ++j) {
      sum[i] += a[j];
    }
  }
}

void update(int x, int y) {
  a[x] += y;
  sum[belong[x]] += y;
}
int query(int x, int y) {
  int ret = 0;
  if (belong[x] == belong[y]) {
    for (int i = x; i <= y; ++i) {
      ret += a[i];
    }
    return ret;
  }

  for (int i = x; i <= r[belong[x]]; ++i) {
    ret += a[i];
  }
  for (int i = belong[x] + 1; i < belong[y]; ++i) {
    ret += sum[i];
  }
  for (int i = l[belong[y]]; i <= y; ++i) {
    ret += a[i];
  }
  return ret;
}
int main() {
  int T;
  scanf("%d", &T);

  int kase = 0;
  while (T--) {
    printf("Case %d:\n", ++kase);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }

    memset(sum, 0, sizeof(sum));
    build();

    char opt[20];
    int x, y;
    for ( ; ; ) {
      scanf("%s", opt);
      char cmd = opt[0];
      if (cmd == 'E') break;

      scanf("%d%d", &x, &y);
      if (cmd == 'Q') {
        printf("%d\n", query(x, y));
      } else if (cmd == 'A') {
        update(x, y);
      } else if (cmd == 'S') {
        update(x, -y);
      }
    }
  }
}
