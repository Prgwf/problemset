#include <bits/stdc++.h>
using namespace std;

const int N = 567;

typedef unsigned long long ull;
int n, m;
char mat[N][N];
ull hs[N * N], hs1[N][N], hs2[N][N];
ull pw1[N], pw2[N];
ull seed1 = 17, seed2 = 9191891;

bool check(int k) {
  int tot = 0;
  for (int i = k; i <= n; ++i) {
    for (int j = k; j <= m; ++j) {
      ull temp = hs2[i][j] - hs2[i][j - k] * pw1[k];
      temp -= hs2[i - k][j] * pw2[k];
      temp += hs2[i - k][j - k] * pw1[k] * pw2[k];
      hs[++tot] = temp;
    }
  }

  sort(hs + 1, hs + 1 + tot);
  for (int i = 1; i <= tot; ++i) {
    if (hs[i] == hs[i - 1])  return 1;
  }      
  return false;
}

int main() {
  pw1[0] = pw2[0] = 1;
  for (int i = 1; i < N; ++i) {
    pw1[i] = pw1[i - 1] * seed1;
    pw2[i] = pw2[i - 1] * seed2;
  }

  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%s", mat[i] + 1);
  
  for (int i = 1; i <= n; ++i) {                 
    for (int j = 1; j <= m; ++j) {
      hs1[i][j] = hs1[i][j - 1] * seed1 + (mat[i][j] - 'a');
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      hs2[i][j] = hs2[i - 1][j] * seed2 + hs1[i][j];
    }
  }

  int mid, ans = 0, lb = 1, ub = min(n, m);
  while (lb <= ub) {
    mid = (lb + ub) / 2;
    if (check(mid)) {
      ans = mid; lb = mid + 1;
    } else {
      ub = mid - 1;
    }
  }
  printf("%d\n", ans);
  return 0;
} 