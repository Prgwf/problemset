/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int main() {
  int n = 50, m = 99;
  vector<pair<int, int>> e;
  for (int j = 1; j <= 49 && m; ++j) {
    for (int i = 1; i + j < 50 && m; ++i) {
      e.push_back({i, i + j});
      m--;
    }
  }
  e.push_back({49, 50});
  printf("%d %d\n", n, e.size());
  for (auto edge : e) {
    printf("%d %d\n", edge.first, edge.second);
  }
}
