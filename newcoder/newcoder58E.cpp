/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 40000 + 20;
const int moder = 1e9 + 7;
const int K = 256;

struct Query {
  int id;
  int l, r, k1, k2;  

  bool operator < (const Query & rhs) const {
    if (l / K != rhs.l / K) {
      return l < rhs.l;
    } else {
      return r < rhs.r;
    }
  }
} ;
int n, m;
int a[maxn];
int real_cnt[maxn];
int cntk[maxn / K + 5];
int cnt[maxn][maxn / K + 5];
int have[maxn];
vector<Query> qs;

void add(int x, int value) {
  int k1;

  k1 = real_cnt[x];
  if (!--have[k1]) {
    cntk[k1 / K]--;
  }
  cnt[k1][x / K]--;

  real_cnt[x] += value;

  k1 = real_cnt[x];
  if (!have[k1]++) {
    cntk[k1 / K]++; 
  }
  cnt[k1][x / K]++;
}

int solve(int k1, int k2) {
  int i = 0;
  while (k1 > cntk[i]) {
    k1 -= cntk[i];
    ++i;
  }
  i *= K;
  while (true) {
    while (have[i] <= 0) {
      ++i;
    }
    if (!--k1) break;
    ++i;
  }

  int j = 0;
  while (k2 > cnt[i][j]) {
    k2 -= cnt[i][j];
    ++j;
  }
  j *= K;
  while (true) {
    while (real_cnt[j] != i) {
      ++j;
    }
    if (!--k2) break;
    ++j;
  }
  return j;
}

int main() {
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }

  scanf("%d", &m);

  for (int i = 0; i < m; ++i) {
    int l, r, k1, k2;
    scanf("%d%d%d%d", &l, &r, &k1, &k2);
    qs.push_back({i, l, r, k1, k2});
  }
  sort(qs.begin(), qs.end());
  
  vector<int> ans(m);
  int l = 1, r = 0;
  for (int i = 0; i < m; ++i) {
    while (r < qs[i].r) {
      add(a[++r], 1);
    }
    while (r > qs[i].r) {
      add(a[r--], -1);
    }
    while (l < qs[i].l) {
      add(a[l++], -1);
    }
    while (l > qs[i].l) {
      add(a[--l], 1);
    }

    ans[qs[i].id] = solve(qs[i].k1, qs[i].k2);
  }

  for (int i : ans) {
    printf("%d\n", i);
  }
}
