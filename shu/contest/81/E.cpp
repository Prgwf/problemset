/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int moder = 1e9 + 7;

string graph[21][21];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void draw(int n) {
  for (int i = 0; i <= 2 * n; ++i) {
    for (int j = 0; j <= 2 * n; ++j) {
      graph[i][j].assign(2 * n + 1, '.');
    }
    graph[i][n][n] = '0' + abs(n - i);
  }

  for (int layer = 0; layer <= 2 * n; ++layer) {
    queue<pair<int, int>> Q;
    map<pair<int, int>, bool> S;
    Q.push({n, n});
    S[make_pair(n, n)] = 1;
    
    while (!Q.empty()) {
      auto pii = Q.front();
      Q.pop();
      
      int x = pii.first;
      int y = pii.second;

      if (graph[layer][x][y] == '0' + n) continue;

      for (int i = 0; i < 4; ++i) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (tx < 0 || tx > 2 * n || ty < 0 || ty > 2 * n) continue;
        if (S.count(make_pair(tx, ty))) continue;
        graph[layer][tx][ty] = graph[layer][x][y] + 1;
        S[make_pair(tx, ty)] = 1;
        Q.push({tx, ty});
      }
    }
  }

  for (int i = 0; i <= 2 * n; ++i) {
    cout << "slice #" << i + 1 << ":\n";
    for (int j = 0; j <= 2 * n; ++j) {
      cout << graph[i][j] << endl;
    }
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  int kase = 0;
  while (T--) {
    cout << "Scenario #" << ++kase << ":\n";

    int n;
    cin >> n;
    if (n == 0) {
      cout << "slice #1:\n0\n";
      cout << endl;
      continue;
    }
    
    draw(n);

    cout << endl;
  }
}
