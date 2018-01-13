/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int moder = 1e9 + 7;


int block[maxn];
struct Query {
  int l, r, p, id; 

  bool operator < (const Query & rhs) const {
    if (block[l] == block[rhs.l]) {
      return r < rhs.r;
    } else {
      return l < rhs.l;
    }
  }
} ;
vector<Query> qs;
map<int, int> cnt;
vector<int> ans;
int a[maxn];
int block_size;
int sum = 0;
int p;
void add(int x) {
  if (cnt.count(x)) {
    cnt[x]++;
  } else {
    cnt[x] = 1;
    sum = (sum + x) % p;
  }
}
void del(int x) {
  if (!--cnt[x]) {
    cnt.erase(x);
    sum = (sum - x + p) % p;
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  block_size = ceil(sqrt(1.0 * n));
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    block[i] = (i - 1) / block_size;
  }

  for (int i = 0; i < m; ++i) {
    int l, r, p;
    scanf("%d%d%d", &l, &r, &p);
    qs.push_back({l, r, p, i});
  }
  sort(qs.begin(), qs.end());

  sum = 0;
  ans.assign(m, 0);
  int l = 1, r = 0, id;
  for (int i = 0; i < m; ++i) {
    id = qs[i].id;
    p = qs[i].p;

    while (r < qs[i].r) {add(a[++r]);}
    while (r > qs[i].r) {del(a[r--]);}
    while (l < qs[i].l) {del(a[l++]);}
    while (l > qs[i].l) {add(a[--l]);}
    ans[id] = sum;
  }

  for (int i = 0; i < m; ++i) {
    printf("%d\n", ans[i]);
  }
}
