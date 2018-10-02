#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int N = 1005;

int n, m, a, b, q;
char mat[N][N];
char qry[N][N];
ull hs1[N][N], hs2[N][N];
ull sd1, sd2, pw1[N], pw2[N];
ull hs[N * N];

int init() {
  sd1 = 131, sd2 = 1789;
  pw1[0] = 1; pw2[0] = 1;
  for (int i = 1; i < N; ++i) {
    pw1[i] = pw1[i - 1] * sd1;
    pw2[i] = pw2[i - 1] * sd2;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      hs1[i][j] = hs1[i][j - 1] * sd1 + mat[i][j] - '0';
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      hs2[i][j] = hs2[i - 1][j] * sd2 + hs1[i][j];
    }
  }
  int tot = 0;
  for (int i = a; i <= n; ++i) {
    for (int j = b; j <= m; ++j) {
      ull temp = hs2[i][j] - hs2[i][j - b] * pw1[b] - hs2[i - a][j] * pw2[a] + hs2[i - a][j - b] * pw1[b] * pw2[a];
      hs[tot++] = temp;
    }
  }
  sort(hs, hs + tot);
  return tot;
}


int main() {
  scanf("%d%d%d%d", &n, &m, &a, &b);
  for (int i = 1; i <= n; ++i) scanf("%s", mat[i] + 1);
  
  int tot = init();
  
  scanf("%d", &q);
  while (q--) {
    for (int i = 1; i <= a; ++i) {
      scanf("%s", qry[i] + 1);
    } 

    ull t = 0;
    for (int i = 1; i <=a; ++i) {
      ull y = 0;
      for (int j = 1; j <= b; ++j) {
        y = y * sd1 + qry[i][j] - '0';
      }
      t = t * sd2 + y;           
    }
    int pos = lower_bound(hs, hs + tot, t) - hs;
    printf("%d\n", pos != tot);      
  }
  return 0;
}