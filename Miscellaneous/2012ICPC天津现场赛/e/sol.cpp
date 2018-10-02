#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int x[N], y[N];
int e[N][N];
int n, d;

int ans[N];
bool vis[N];
bool check() {
  memset(vis, 0, sizeof(vis));
  queue<int> Q;
  Q.push(0);
  vis[0] = 1;

  while (Q.size()) {
    int u = Q.front(); 
    Q.pop();

    for (int v = 0; v < n; ++v) if (not vis[v]) {
      if (ans[v] and d >= e[u][v]) {
        Q.push(v); 
        vis[v] = 1;  
      } else if (not ans[v] and d >= 2 * e[u][v]) {
        vis[v] = 1;
      }
    }
  }
  
  for (int i = 0; i < n; ++i) if (not vis[i]) return 0;
  return 1;
}

int main() {
  while (scanf("%d %d", &n, &d) != EOF) {
    for (int i = 0; i < n; ++i) scanf("%d %d", &x[i], &y[i]);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        e[j][i] = e[i][j] = ceil(hypot(x[i] - x[j], y[i] - y[j]));
      }
    }

    for (int i = 0; i < n; ++i) ans[i] = 1;
    if (!check()) {
      puts("-1");
      continue;
    }
    
    for (int i = n - 1; i; --i) {
      ans[i] = 0;
      if (!check()) ans[i] = 1;
    }
    
    int j;
    for (j = n - 1; j; --j) {
      if (ans[j]) break;
    }
    for (int i = j; ~i; --i) {
      printf("%d", ans[i]);
    }
    printf("\n");
  }  
}