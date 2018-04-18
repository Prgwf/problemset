/*
教练我想打ACM~
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 10000000 + 7;

int n, m;
int id, root;
int son[maxn][2];
int cnt[maxn];
int new_node() {
  ++id;
  son[id][0] = son[id][1] = -1;
  cnt[id] = 0;
  return id;
}

void insert(int x) {
  int now = root, k;
  for (int i = 17; ~i; --i) {
    k = x >> i & 1;
    if (son[now][k] < 0) {
      son[now][k] = new_node();
    }
    now = son[now][k];
    cnt[now]++;
  }
}

int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    id = 0;
    root = new_node();
    long long ans = 0LL;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      int u = root;
      for(int j = 17; ~j; --j) {
        int t = x >> j & 1;
        if (m >> j & 1) {
          u = son[u][t ^ 1];
        } else {
          ans += 1LL * cnt[son[u][t ^ 1]];
          u = son[u][t];
        }
      }
      insert(x);
    }
    printf("%lld\n", ans);
  }
}
