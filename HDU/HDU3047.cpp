/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int n, m;
int fa[maxn], rnk[maxn];
void init() {
  for (int i = 1; i <= n; ++i) {
    fa[i] = i;
    rnk[i] = 0;
  }
}
int find(int x) {
  if (x != fa[x]) {
    int t = fa[x];
    fa[x] = find(fa[x]);
    rnk[x] = (rnk[x] + rnk[t]) % 300;
  }
  return fa[x];
}
void unite(int x, int y, int r) {
  int fx = find(x);
  int fy = find(y);
  if (fx == fy) return;
  fa[fx] = fy;
  rnk[fx] = (r + rnk[y] - rnk[x] + 300) % 300;
}
int check(int x, int y, int r) {
  int fx = find(x);
  int fy = find(y);
  if (fx == fy) {
    return r == ((rnk[x] - rnk[y]) % 300 + 300) % 300;
  }
  return 1;
}
void work() {
  while (scanf("%d%d", &n, &m) != EOF) {
    init();
    int ans =0;
    for (int i = 0; i < m; ++i) {
      int x, y, r;
      scanf("%d%d%d", &x, &y, &r);
      if (check(x, y, r)) {
        unite(x, y, r);
      } else {
        ans++;
      }
    }
    printf("%d\n", ans);
  }
}
int main() {
  // freopen("data.in", "r", stdin);
  // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  work();
}
