/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

typedef long long ll;
typedef __gnu_pbds::tree<int, 
        __gnu_pbds::null_type, 
        less<int>, 
        __gnu_pbds::rb_tree_tag,
        __gnu_pbds::tree_order_statistics_node_update> Set;

const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 20;
const int moder = 1e9 + 7;

int n, m;
int blksz;
int blk[maxn];
struct Query {
  int id;
  int l, r;
  int k1, k2;
  bool operator < (const Query & rhs) const {
    if (blk[l] == blk[rhs.l]) {
      return r < rhs.r;
    } else {
      return l < rhs.l;
    }
  }
} ;
vector<Query> qs;
vector<int> ans;
int a[maxn];
map<int, int> cnt;
map<int, Set> rcnt;
Set rnk;

void add(int x) {
  if (cnt.count(x)) {
    rcnt[cnt[x]].erase(x);
    if (!rcnt.count(cnt[x])) {
      rnk.erase(cnt[x]);
    }
    cnt[x]++;
    rcnt[cnt[x]].insert(x);
    rnk.insert(cnt[x]);
  } else {
    cnt[x] = 1;
    rcnt[cnt[x]].insert(x);
    rnk.insert(1);
  } 
}

void erase(int x) {
  rcnt[cnt[x]].erase(x);
  if (!rcnt.count(cnt[x])) {
    rnk.erase(cnt[x]);
  }
  cnt[x]--;
  if (cnt[x]) {
    rcnt[cnt[x]].insert(x);
    rnk.insert(cnt[x]);
  }
}
int main() {
  scanf("%d", &n);
  blksz = ceil(sqrt(1.0 * n));

  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    blk[i] = (i - 1) / blksz;
  }

  scanf("%d", &m);
  ans.resize(m);
  for (int i = 0; i < m; ++i) {
    int l, r, k1, k2;
    scanf("%d%d%d%d", &l, &r, &k1, &k2);

    qs.push_back({i, l, r, k1, k2});
  }
  sort(qs.begin(), qs.end());
  
  int l = 1, r = 0;
  for (int i = 0; i < m; ++i) {
    while (r < qs[i].r) {
      add(a[++r]);
    }
    while (r > qs[i].r) {
      erase(a[r--]);
    }
    while (l < qs[i].l) {
      erase(a[l++]);
    }
    while (l > qs[i].l) {
      add(a[--l]);
    }

    int k = *rnk.find_by_order(qs[i].k1 - 1);
    ans[qs[i].id] = *rcnt[k].find_by_order(qs[i].k2 - 1);
  }

  for (int x : ans) {
    printf("%d\n", x);
  }
}
