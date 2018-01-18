/*
教练我想打ACM~
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 10000 + 7;
const int K = 32;

int n, m;
int a[maxn];
int b[maxn], siz;
int c[K][maxn];
int cnt[K];
int block, num, l[maxn], r[maxn], belong[maxn];
ll ans;

void add(int i, int x, int k) {
  while (x <= n) {
    c[i][x] += k;
    x += x & (-x);
  }
}

int sum(int i, int x) {
  int ret = 0;
  while (x) {
    ret += c[i][x];
    x -= x & (-x);
  }
  return ret;
}

void build() {
  block = pow(1.0 * n, 2.0 / 3.0);
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
    for (int j = r[i]; j >= l[i]; --j) {
      cnt[i] += sum(i, a[j]);
      add(i, a[j], 1);
    }
  }
}

void update(int x, int y) {
  if (x == y || a[x] == a[y]) {
    printf("%lld\n", ans);
    return;
  }
  if(x > y) swap(x, y);

  swap(a[x], a[y]);
}


int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    a[i] = b[i - 1] = x;
  }
  sort(b, b + n);
  siz = unique(b, b + n) - b;
  for (int i = 1; i <= n; ++i) {
    a[i] = lower_bound(b, b + n, a[i]) - b + 1;
  }

  build();

  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    update(x, y);
  }
}
