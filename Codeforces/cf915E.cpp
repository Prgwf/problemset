/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 15000000 + 20;
const int moder = 1e9 + 7;

struct node {
  int sum;
  short lazy;
  int lson, rson;
} a[maxn];
int id = 0;
int new_node() {
  int o = ++id;
  a[o].sum = 0;
  a[o].lazy = -1;
  a[o].lson = a[o].rson = 0;
  return o;
}

void push_down(int o, int l, int r) {
  if (a[o].lazy != -1) {
    int m = (l + r) / 2;
    if (a[o].lson == 0) a[o].lson = new_node();
    if (a[o].rson == 0) a[o].rson = new_node();
    
    int lo = a[o].lson;
    a[lo].sum = (m - l + 1) * a[o].lazy;
    a[lo].lazy = a[o].lazy;
    int ro = a[o].rson;
    a[ro].sum = (r - m) * a[o].lazy;
    a[ro].lazy = a[o].lazy;

    a[o].lazy = -1;
  }
}

void push_up(int o) {
  a[o].sum = a[a[o].lson].sum + a[a[o].rson].sum;
}

void update(int &o, int ql, int qr, int k, int l, int r) {
  if (o == 0) {
    o = new_node();
    a[o].sum = (r - l + 1) * k;
    a[o].lazy = k;
  }  

  if (ql <= l && r <= qr) {
    a[o].sum = (r - l + 1) * k;
    a[o].lazy = k;
    return;
  }

  push_down(o, l, r);

  int m = (l + r) / 2;
  if (ql <= m) update(a[o].lson, ql, qr, k, l, m);
  if (qr > m) update(a[o].rson, ql, qr, k, m + 1, r);
  push_up(o);
}

int query(int o, int ql, int qr, int l, int r) {
  if (o == 0 || a[o].sum == 0) {
    return 0;
  }

  if (ql <= l && r <= qr) {
    return a[o].sum;
  }
  
  push_down(o, l, r);
  
  int m = (l + r) / 2;
  int ret = 0;
  if (l <= m)  ret = query(a[o].lson, ql, qr, l, m);
  if (r > m) ret += query(a[o].rson, ql, qr, m + 1, r);
  push_up(o);
  return ret;
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);

  int root = 0;
  update(root, 1, n, 1, 1, n);
  while (q--) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    update(root, l, r, k - 1, 1, n);
    printf("%d\n", a[root].sum);
  }
}
