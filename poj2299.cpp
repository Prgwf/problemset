#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long i64;

const int N = 500000 + 5;

#define all(x) (x).begin(), (x).end()
#define lson o<<1
#define rson o<<1|1


struct node {
  int l, r, sum;
} T[N * 6];

void push_up(int o) {
  T[o].sum = T[lson].sum + T[rson].sum;
}

void build(int l, int r, int o = 1) {
  T[o].l = l; T[o].r = r; T[o].sum = 0;
  if (l == r) {
    return;
  }  
  int mid = (l + r) / 2;
  build(l, mid, lson);
  build(mid + 1, r, rson);
  push_up(o);
}

void update(int pos, int o = 1) {
  if (T[o].r < pos or T[o].l > pos) return;
  if (T[o].l == pos && T[o].l == T[o].r) {
    T[o].sum++;
    return;
  }

  update(pos, lson);
  update(pos, rson);
  push_up(o);
}

int query(int l, int r, int o = 1) {
  if (T[o].r < l or T[o].l > r) return 0;
  if (l <= T[o].l and T[o].r <= r) return T[o].sum;
  return query(l, r, lson) + query(l, r, rson);
}

int n, a[N];


int main() {
  while (scanf("%d", &n) != EOF && n) {
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    vector<int> disc(a, a + n);
    sort(all(disc));
    disc.erase(unique(all(disc)), disc.end());
    for (int i = 0; i < n; ++i) a[i] = lower_bound(all(disc), a[i]) - disc.begin() + 1;
    i64 ans = 0;
    build(1, n);
    for (int i = 0; i < n; ++i) {
      ans +=  query(a[i] + 1, n);
      update(a[i]);
    }
    printf("%lld\n", ans);
  }  
}