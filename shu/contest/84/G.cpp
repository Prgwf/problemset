/*
教练我想打ACM~
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100 + 7;

int n, m;
int g[maxn][maxn];
void floyd() {
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) if (i != k) {
      for (int j = 0; j < n; ++j) if (j != i && j !=- k) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (g[i][j] < inf) {
        ans = max(ans, g[i][j]);
      }
    }
  }
  printf("%d\n", ans);
}

int main() {
  while (scanf("%d%d", &n, &m) && (n + m)) {
    memset(g, inf, sizeof(g));
    for (int i = 0; i < m; ++i) {
      int u, v, d;
      scanf("%d%d%d", &u, &v, &d);
      if (u > v) swap(u, v);
      if (g[u][v]) {
        g[u][v] = min(g[u][v], d);
      }
      g[v][u] = g[u][v];
    }

    floyd();
  }
}
