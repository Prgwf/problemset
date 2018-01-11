/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 10000 + 20;
const int moder = 10000;

struct Solution {
  int n, m;
  vector<ll> dp;
  vector<vector<int>> g;
  int fa[maxn];
  int mxd;

  int find(int x) {
    if (x != fa[x]) {
      fa[x] = find(fa[x]);
    }
    return fa[x];
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    fa[x] = y;
  }

  ll dfs(int x, int p, int depth) {
    if (depth > mxd) {
      return 0;
    }
    if (x == n - 1 && depth == mxd) {
      return 1;
    }

    if (dp[x]) {
      return dp[x];
    }

    for (int v : g[x]) {
      if (v != p) {
        dp[x] += dfs(v, x, depth + 1);
        dp[x] %= moder;
      }
    }

    return dp[x];
  }

  void work() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
      scanf("%d%d", &n, &m);
      g.clear();
      g.resize(n);
      for (int i = 0; i < n; ++i) {
        fa[i] = i;
      }

      for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
        unite(x, y);
      }

      if (find(0) != find(n - 1)) {
        puts("-1");
        continue;
      }

      vector<int> dist(n, inf);
      queue<int> Q;
      dist[0] = 0;
      Q.push(0);

      int ans = 0;
      while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (int v : g[u]) {
          if (dist[v] >= dist[u] + 1) {
            dist[v] = dist[u] + 1;
            Q.push(v);
            if (v == n - 1) {
              ans++;
              ans %= moder;
            }
          }
        }
      }
      

      // dp.assign(n, 0);
      // int ans = dfs(0, -1, 0);
      printf("%d\n", ans);
    }
  }

} ; 
Solution Woo;
int main() {
  Woo.work();
}



