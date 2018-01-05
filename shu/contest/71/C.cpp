/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 200 + 20;
const int moder = 1e9 + 7;

struct Solution {
  int n;
  int a[maxn];
  int g[maxn][maxn];
  int nxt[maxn];
  int dp[maxn];
  int dfs(int v) {
    if (dp[v]) return dp[v];

    for (int u = 0; u < n; ++u) {
      if (g[v][u]) {
        int t = dfs(u) + a[u];
        if (dp[v] < t) {
          dp[v] = t;
          nxt[v] = u;
        }
      }
    }
    return dp[v];
  }
  void work(istream &in, ostream &out) {
    in >> n;

    for (int i = 0; i < n; ++i) {
      in >> a[i];
    }

    memset(g, 0, sizeof(g));
    int x, y;
    while (in >> x >> y) {
      if (!(x + y)) break;

      --x; --y;
      g[x][y] = 1;
    }

    memset(dp, 0, sizeof(dp));
    memset(nxt, -1, sizeof(nxt));
    for (int i = 0; i < n; ++i) {
      if (!dp[i]) dfs(i);
    }

    int ans = 0, v;
    for (int i = 0; i < n; ++i) {
      if (ans < dp[i] + a[i]) {
        ans = dp[i] + a[i];
        v = i;
      }
    }

    out << v + 1;
    while (nxt[v] != -1) {
      v = nxt[v];
      out << '-' << v + 1;
    }
    out << "\n" << ans << endl;
  } 

} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work(cin, cout);
}

