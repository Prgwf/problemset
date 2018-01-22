/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int n, m;
int a[maxn];
int b[maxn];
int c[maxn];
int disc[maxn];
int block, num;
int belong[maxn];
int l[maxn], r[maxn];
int ans;

void add(int x, int k) {
  while (x <= n) {
    c[x] += k;
    x += x & (-x);
  }
}

int sum(int x) {
  int ret = 0;
  while (x) {
    ret += c[x];
    x -= x & (-x);
  }
  return ret;
}

void rebuild(int x) {
  for (int i = l[x]; i <= r[x]; ++i) {
    a[i] = b[i];
  }
  sort(a + l[x], a + r[x] + 1);
}

void build() {
  block = sqrt(n);
  num = n / block;
  if (n % block) num++;
  for (int i = 1; i <= num; ++i) {
    l[i] = (i - 1) * block + 1;
    r[i] = i * block;
  }
  r[i] = num;
  for (int i = 1; i <= n ++i) {
    belong[i] = (i - 1) / block;
    rebuild(i);
  }
}


void solve(int x, int y) {
  if (x == y || b[x] == b[y]) {
    return;
  }
  if (b[x] < b[y]) ++ans;
  if (b[x] > b[y]) --ans;
  if (belong[x] == belong[y]) {
    for (int i = x + 1; i < y; ++i) {
      
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    a[i] = b[i] = disc[i - 1] = x;
  }
  sort(disc, disc + n);
  int siz = unique(disc, disc + n) - disc;
  for (int i = 1; i <= n; ++i) {
    a[i] = b[i] = lower_bound(disc, disc + siz, a[i]) - disc + 1;
  }

  for (int i = 1; i <= n; ++i) {
    ans += sum(a[i] - 1);
    add(a[i], 1);
  }

  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    solve(x, y);
    printf("%d\n", ans);
  }

}
