/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 20;

struct TwoSAT {
  int n;
  vector<int> G[maxn * 2];
  int S[maxn * 2], c;
  bool mark[maxn * 2];
  void init(int n) {
    this->n = n;
    for (int i = 0; i < n * 2; ++i) G[i].clear();
    memset(mark, 0, sizeof(mark));
  }
  void add_clause(int x, int xval, int y, int yval) {
    x = x * 2 + xval;
    y = y * 2 + yval;
    G[x ^ 1].push_back(y);
    G[y ^ 1].push_back(x);
  }
  bool DFS(int x) {
    if (mark[x ^ 1]) return false;
    if (mark[x]) return true;
    S[c++] = x;
    mark[x] = true;
    for (int i = 0; i < G[x].size(); ++i) {
      if (!DFS(G[x][i])) return false;
    }
    return true;
  }
  bool run() {
    for (int i = 0; i < n * 2; i += 2) {
      if (!mark[i] && !mark[i + 1]) {
        c = 0;
        if (!DFS(i)) {
          while (c > 0) mark[S[--c]] = false;
          if (!DFS(i + 1)) return false;
        }
      }
    }
    return true;
  }
} tsat;
int N, M;
int x[maxn], y[maxn];
void work() {
  /*
  0 --> in circle
  1 --> out circle
  */
  tsat.init(N);
  for (int i = 0; i < M; ++i) {
    scanf("%d%d", x + i, y + i);
    if (x[i] > y[i]) swap(x[i], y[i]);
  }
  for (int i = 0; i < M; ++i) {
    for (int j = i + 1; j < M; ++j) {
      if ( (x[i] <= x[j] && y[i] <= y[j] && y[i] >= x[j])
        || (x[i] >= x[j] && y[i] >= y[j] && x[i] <= y[j])) {
        tsat.add_clause(i, 0 ^ 1, j, 0 ^ 1);
        tsat.add_clause(i, 1 ^ 1, j, 1 ^ 1);
      }
    }
  }
  printf("%s\n", tsat.run() == true ? "panda is telling the truth..." : "the evil panda is lying again");
}
int main() {
  while (scanf("%d%d", &N, &M) != EOF) {
    work();
  }
}
