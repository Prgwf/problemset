#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define lson o<<1
#define rson o<<1|1
const int N = 300030;
const int X = 1000001;

int n, m;
int a[N], d[X];
struct node {
  int l, r;
  ll sum, max;
} st[N << 2];

void init() {
  for (int i = 1; i < X; ++i) 
    for (int j = i; j < X; j += i) d[j]++;
}

void push_up(int o) {
  st[o].sum = st[lson].sum + st[rson].sum;
  st[o].max = max(st[lson].max, st[rson].max);
}

void build(int l = 1, int r = n, int o = 1) {
  st[o].l = l; st[o].r = r; st[o].sum = st[o].max = 0;
  if (l == r) {
    st[o].sum = st[o].max = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, lson);
  build(mid + 1, r, rson);
  push_up(o);
}

void advance(int l, int r, int o = 1) {
  if (st[o].r < l or st[o].l > r or st[o].max <= 2) return;
  if (st[o].l == st[o].r) {
    st[o].sum = st[o].max = d[st[o].sum];
    return;
  }
  advance(l, r, lson);
  advance(l, r, rson);
  push_up(o);
}

ll query(int l, int r, int o = 1) {
  if (st[o].r < l or st[o].l > r) return 0;
  if (l <= st[o].l and st[o].r <= r) return st[o].sum;
  return query(l, r, lson) + query(l, r, rson);
}

int main() {
  init();
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  build();
  for (int i = 0; i < m; ++i) {
    static int l, r, t;
    scanf("%d %d %d", &t, &l, &r);
    if (t == 1) {
      advance(l, r);
    } else {
      printf("%lld\n", query(l, r));
    }
  } 
}