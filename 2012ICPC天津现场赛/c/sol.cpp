#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;

int f[1050][10][10][10];

int n;
char s1[1050], s2[1050];
int u[1050], v[1050];


int dfs(int i, int x, int y, int z) {
  if (i >= n) return 0;
  if (~f[i][x][y][z]) return f[i][x][y][z];

  int & dp = f[i][x][y][z];
  
  dp = inf;
  int tar = v[i];
  if (tar > x) {
    int d = tar - x;
    for (int j = 0; j <= d; ++j) {
      for (int k = 0; k <= j; ++k) {
        dp = min(dp, dfs(i + 1, (y + j) % 10, (z + k) % 10, u[i + 3]) + d);  
      }
    }
    
    d = 10 - d;
    for (int j = 0; j <= d; ++j) {
      for (int k = 0; k <= j; ++k) {
        dp = min(dp, dfs(i + 1, (y - j + 10) % 10, (z - k + 10) % 10, u[i + 3]) + d);  
      }
    }
  } else {
    int d = 10 - (x - tar);
    for (int j = 0; j <= d; ++j) {
      for (int k = 0; k <= j; ++k) {
        dp = min(dp, dfs(i + 1, (y + j) % 10, (z + k) % 10, u[i + 3]) + d);  
      }
    }
    
    d = x - tar;
    for (int j = 0; j <= d; ++j) {
      for (int k = 0; k <= j; ++k) {
        dp = min(dp, dfs(i + 1, (y - j + 10) % 10, (z - k + 10) % 10, u[i + 3]) + d);  
      }
    }    
  }

  return dp;
}

int main() {
  while (scanf("%s%s", s1, s2) != EOF) {
    memset(u, 0, sizeof(u));
    memset(v, 0, sizeof(v));
    
    n = strlen(s1);
    for (int i = 0; i < n; ++i) u[i] = s1[i] - '0';
    for (int i = 0; i < n; ++i) v[i] = s2[i] - '0';
    
    memset(f, 0xff, sizeof(f));
    printf("%d\n", dfs(0, u[0], u[1], u[2]));
  }
}