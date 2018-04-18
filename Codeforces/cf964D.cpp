#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 20;

int n;
int deg[N], depth[N];
int vis[N];
vector<int> ans;
vector<vector<int>> T;
void dfs(int x, int p) {
  for (int v : T[x]) {
    if (v == p) continue;
    dfs(v, x);
  }

  if (deg[x] % 2 == 0 && vis[x] == 0) {
    ans.push_back(x);
    vis[x] = 1;
    for (int v : T[x]) {
      if (--deg[v] == 0 && vis[v] == 0) {
        ans.push_back(v);
        vis[v] = 1;
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  scanf("%d", &n);
  T.resize(n + 1, vector<int>());
  for (int i = 1; i <= n; ++i) {
    int u;
    scanf("%d", &u);
    if (not u) continue;
    T[i].push_back(u);
    T[u].push_back(i);
    deg[u]++;
    deg[i]++;
  }

  if (not(n & 1)) {
    printf("NO\n");
    return 0;
  }

  printf("YES\n");
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      dfs(i, -1);
    }
  }
  for (int x : ans) {
    printf("%d ", x);
  }
  return 0;
}