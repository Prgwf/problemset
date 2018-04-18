/*
   教练我想打ACM～
   */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int moder = 1e9 + 7;

struct Solution {
  vector<vector<pair<int, int>>> g;
  int flag;
  vector<bool> vis;
  vector<int> dist;

  void dfs(int x) {
    vis[x] = true;

    for (auto pii : g[x]) {
      int v = pii.first;
      int d = pii.second;
      if (dist[v] > dist[x] + d) {
        dist[v] = dist[x] + d;
        if (vis[v]) {
          flag = true;
          return;
        } 
        dfs(v);
      }
    }

    vis[x] = false;    
  }

  void work() {
    int T;
    scanf("%d", &T);

    while (T--) {
      int n, m, w;
      scanf("%d%d%d", &n, &m, &w);
      g.clear();
      g.resize(n + 2);

      for (int i = 0; i < m; ++i) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        g[x].push_back({y, c});
        g[y].push_back({x, c});
      }

      for (int i = 0; i < w; ++i) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        g[x].push_back({y, -c});
      }

      flag = 0;
      vis.assign(n + 2, 0);
      dist.assign(n + 2, 0);
      for (int i = 1; i <= n; ++i) {
        dfs(i);
        if (flag) break;
      }
      printf("%s\n", flag ? "YES" : "NO");

    }
  }

} ; 
Solution Woo;
int main() {
  Woo.work();
}

