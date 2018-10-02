/*
教练我想打ACM~
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 7;

int n;
vector<vector<int>> T;
int sz[maxn];
int ans, mxsiz;
void dfs(int v, int p) {
  sz[v] = 1;
  int temp = 0;
  for (int u : T[v]) {
    if (u != p) {
      dfs(u, v);
      sz[v] += sz[u];
      temp = max(temp, sz[u]);
    }
  }

  temp = max(temp, n - sz[v]);
  if ((temp < mxsiz) || (temp == mxsiz && v < ans)) {
    ans= v;
    mxsiz = temp;
  }
}
int main() {
  while (~scanf("%d", &n)) {
    T.assign(n * 2, vector<int>());
    for (int i = 1; i < n; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      --x; --y;
      T[x].push_back(y);
      T[y].push_back(x);
    }
    mxsiz = inf;
    memset(sz, 0, sizeof(sz));
    dfs(0, -1);
    printf("%d %d\n", ans + 1, mxsiz);
  }
}
