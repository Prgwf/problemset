#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, char>>> G;
int dp[205][205][30];

int dfs(int x, int y, int state) {
  if (~dp[x][y][state])  return dp[x][y][state];
  
  int & now = dp[x][y][state];
  for (auto pii : G[x]) {
    int v = pii.first;
    int value = pii.second;
    if (value < state) continue;
    if (!dfs(y, v, value)) {
      return now = 1;
    }
  }
  return now = 0;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  G.assign(n + 2, vector<pair<int, char>>());

  int x, y;
  char ch[2];
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%s", &x, &y, ch);
    G[x].push_back({y, ch[0] - 'a'});
  }

  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      dfs(i, j, 0);
      if (dp[i][j][0]) {
        cout << "A";
      } else {
        cout << "B";
      }
    }
    cout << endl;
  }
}