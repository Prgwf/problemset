#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2e5 + 5;

#define all(x) (x).begin(), (x).end()
#define lson o<<1
#define rson o<<1|1


int a[N];

int n, m, q, x, y, k;

struct node {
  int l, r, sum;
} T[N * 4];

void push_up(int o) {
  T[o].sum = T[lson].sum + T[rson].sum;
}

void build(int l, int r, int o = 1) {
  T[o].l = l; T[o].r = r;
  T[o].sum = (l == 1 ? n : 0);

  if (l == r) return;
  
  int mid = (l + r) / 2;
  build(l, mid, lson);
  build(mid + 1, r, rson);
  push_up(o);
}

void update(int pos, int x, int o = 1) {
  if (T[o].l == pos && T[o].l == T[o].r) {
    T[o].sum += x;
    return;
  }  
  int mid = (T[o].l + T[o].r) / 2;
  if (pos <= mid) update(pos, x, lson);
  else update(pos, x, rson);
  push_up(o);
}

int query(int k, int o = 1) {
  if (T[o].l == T[o].r) {
    return T[o].l;
  }
  // int mid = (T[o].l + T[o].r) / 2;
  if (k <= T[rson].sum) return query(k, rson);
  else return query(k - T[rson].sum , lson); 
}

int fa[N];
int find(int x) {
  if (x != fa[x]) fa[x] = find(fa[x]);
  return fa[x];
}


int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    a[i] = 1;
    fa[i] = i;
  }
  build(1, n);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &q);
    if (q) {
      scanf("%d", &k);
      printf("%d\n", query(k));
    } else {
      scanf("%d %d", &x, &y);
      x = find(x); y = find(y);
      if (x == y) continue;
      update(a[x], -1);
      update(a[y], -1);
      update(a[x] + a[y], 1);
      fa[y] = x; a[x] += a[y];
    }
  }  
}