/*
教练我想打ACM~
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = (1 << 21) + 5;

int n, m, k;
ll a[maxn];
ll sum, cnt[2000000 + 20];
int blk[maxn], blksiz;
struct Query {
  int id;
  int l, r;
  operator < (const Query & rhs) const {
    if (blk[l] == blk[rhs.l]) {
      return r < rhs.r;
    } else {
      return l < rhs.l;
    }
  }
} ;
vector<Query> qs;
/*
x ^ y = k
x ^ k = y
*/
void add(int x) {
  sum += cnt[x ^ k];
  cnt[x]++;
}

void erase(int x) {
  cnt[x]--;
  sum -= cnt[x ^ k];
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  blksiz = sqrt(n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
    a[i] ^= a[i - 1];
    blk[i] = (i - 1) / blksiz;
  }
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    qs.push_back({i, x - 1, y});
  }
  sort(qs.begin(), qs.end());

  int l = 1, r = 0;
  sum = 0;
  vector<ll> ans(m);
  for (int i = 0; i < m; ++i) {
    while (l < qs[i].l) {
      erase(a[l++]);
    }
    while (l > qs[i].l) {
      add(a[--l]);
    }
    while (r < qs[i].r) {
      add(a[++r]);
    }
    while (r > qs[i].r) {
      erase(a[r--]);
    }
    ans[qs[i].id] = sum;
  }

  for (int i = 0; i < m; ++i) {
    printf("%lld\n", ans[i]);
  }
}
