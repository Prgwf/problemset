/*
教练我想打ACM～
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 2000 + 20;
const int moder = 1e9 + 7;

#define lson o << 1
#define rson o << 1 | 1

struct info {
  int l, r, h;
  int t;

  info() {}
  info(int l, int r, int h, int t) : l(l), r(r), h(h) , t(t) {}

  bool operator < (const info & rhs) const {
    return h < rhs.h;
  }
} ;
vector<info> a[1005];
vector<int> xset[1005];

struct Segtree {
  int l, r, val;
  int sum;
} seg[maxn * 12];

void push_up(int z, int o) {
  if (seg[o].val) {
    seg[o].sum = xset[z][seg[o].r] - xset[z][seg[o].l];
    return;
  }
  if (seg[o].l + 1 == seg[o].r) {
    seg[o].sum = 0;
    return;
  }
  seg[o].sum = seg[lson].sum + seg[rson].sum;
}

void build(int l, int r, int o = 1) {
  seg[o].l = l;
  seg[o].r = r;
  seg[o].val = 0;
  seg[o].sum = 0;

  if (l + 1 == r) {
    return;
  }
  int m = (l + r) / 2;
  build(l, m, lson);
  build(m, r, rson);
}

void update(int z, int ul, int ur, int val, int o = 1) {
  if (ul <= seg[o].l && seg[o].r <= ur) {
    seg[o].val += val;
    push_up(z, o);
    return;
  }
  int m = (seg[o].l + seg[o].r) / 2;
  if (ul < m) update(z, ul, ur, val, lson);
  if (ur > m) update(z, ul, ur, val, rson);
  push_up(z, o);
}
int main() {
  int T;
  scanf("%d", &T);

  int kase = 0;
  while (T--) {
    int x1, y1, z1;
    int x2, y2, z2;
    scanf("%d%d%d", &x1, &y1, &z1);
    scanf("%d%d%d", &x2, &y2, &z2);

    for (int i = 0; i <= 1000; ++i) {
      xset[i].clear();
      a[i].clear();
    } 

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      int tx1, ty1, tz1;
      int tx2, ty2, tz2;
      scanf("%d%d%d", &tx1, &ty1, &tz1);
      scanf("%d%d%d", &tx2, &ty2, &tz2);

      if (tx1 >= tx2 || ty1 >= ty2 || tz1 >= tz2) continue;

      tx1 = max(tx1, x1);
      ty1 = max(ty1, y1);

      tx2 = min(tx2, x2);
      ty2 = min(ty2, y2);


      tz1 = max(tz1, z1);
      tz2 = min(tz2, z2);

      if (tx1 >= tx2 || ty1 >= ty2 || tz1 >= tz2) continue;

      for (int j = tz1; j < tz2; ++j) {
        a[j].push_back(info(tx1, tx2, ty1, 1));
        a[j].push_back(info(tx1, tx2, ty2, -1));
        xset[j].push_back(tx1);
        xset[j].push_back(tx2);
      }
    }

    for (int i = z1; i <= z2; ++i) {
      sort(a[i].begin(), a[i].end());

      sort(xset[i].begin(), xset[i].end());
      xset[i].erase(unique(xset[i].begin(), xset[i].end()), xset[i].end());
    }
    
    int ans = 0;
    for (int z = z1; z <= z2; ++z) {
      build(0, xset[z].size() + 5);
      vector<info> & line = a[z];
      int siz = line.size();
      for (int i = 0; i < siz - 1; ++i) {
        int l = lower_bound(xset[z].begin(), xset[z].end(), line[i].l) - xset[z].begin();
        int r = lower_bound(xset[z].begin(), xset[z].end(), line[i].r) - xset[z].begin();
        update(z, l, r, line[i].t);
        ans += seg[1].sum * (line[i + 1].h - line[i].h);
      }
    }
    
    printf("Scenario #%d:\n%d\n", ++kase, ans);
    puts("");
  }
}
