/*
教练我想打ACM~
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 200 + 7;

int n, m;
int acm[maxn], cake[maxn], power[maxn];
int vis[maxn];
int L[maxn];
bool g[maxn][maxn];

bool dfs(int v) {
  for (int u = 1; u <= m; ++u) {
    if (g[v][u] && !vis[u]) {
      vis[u] = 1;
      if (L[u] == -1 || dfs(L[u])) {
        L[u] = v;
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", acm + i);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", power + i);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
      scanf("%d", cake + i);
    }

    memset(g, 0, sizeof(g));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (power[i] >= abs(acm[i] - cake[j])) {
          g[i][j] = 1;
        }
      }
    }

    int ans = 0;
    memset(L, -1, sizeof(L));
    for (int i = 1; i <= n; ++i) {
      memset(vis, 0, sizeof(vis));
      if (dfs(i)) ++ans;
    }
    printf("%d\n", ans);
  }
}
