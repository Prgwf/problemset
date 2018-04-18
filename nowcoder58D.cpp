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
int block_size;
struct Query {
  int l, r, k1, k2, id;
  
  Query() {}
  Query(int l, int r, int k1, int k2, int id) : l(l), r(r), k1(k1), k2(k2), id(id) {}

  bool operator < (const Query & rhs) const {
    if (block[l] == block[rhs.l]) {
      return r < rhs.r;
    } else {
      return l < rhs.l;
    }
  }
} ;
vector<Query> qs;
vector<int> a;
map<int, int> cnt;
map<int, int> rcnt;
vector<int> ans;
int ret;
void add(int x) {

}

void del(int x) {

}
int main() {
  int n;
  scanf("%d", &n);

  block_size = ceil(sqrt(1.0 * n));
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    a.push_back(x);
    block[i] = (i - 1) / block_size;
  }

  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int l, r, k1, k2;
    scanf("%d%d%d%d", &l, &r, &k1, &k2);
    qs.emplace_back(l, r, k1, k2, i);
  }
  sort(qs.begin(), qs.end());

  int l = 1, r = 0;
  for (int i = 0; i < n; ++i) {
    while (r < qs[i].r) {
      add(a[++r]);
    }

    while (r > qs[i].r) {
      del(a[r--]);
    }


    while (l < qs[i].l) {
      del(a[l++]);
    }

    while (l > qs[i].l) {
      add(a[--l]);
    }

    ans[qs[i].id] = ret;
  }
}
