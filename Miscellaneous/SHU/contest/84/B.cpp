/*
教练我想打ACM~
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 100000 + 7;

int n;
int a[5];
int vis[maxn];
void dfs(int x, int sum) {
  if (x == n) {
    vis[sum] = 1;
    return;
  }
  dfs(x + 1, sum);
  dfs(x + 1, sum + a[x]);
}
int main() {
  while (~scanf("%d", &n) && n) {
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    sort(a, a + n);
    memset(vis, 0, sizeof(vis));
    dfs(0, 0);

    for (int i = 1; i <= 4 * 200; ++i) {
      if (!vis[i]) {
        printf("%d\n", i);
        break;
      }
    }
  }
}
