#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int N = 1e6 + 5;

int q, l, r, k;

int c[N][10];
void add(int x, int y, int k) {
  while (x < N) {
    c[x][y] += k;
    x += x & (-x);
  }
}

int sum(int x, int y) {
  int s = 0;
  while (x) {
    s += c[x][y];
    x -= x & (-x);
  }
  return s;
}

int f[N];
int g(int n) {
  if (n < 10) return n;
  
  if (~f[n]) return f[n];
  int m = n;

  int j = 1;
  while(n) {
    int i = n % 10;
    if (i) j *= i;
    n /= 10;
  }
  return f[m] = g(j);
}

int main() {
  memset(f, 0xff, sizeof(f));  
  for (int i = 1; i <= 1e6; ++i) {
    add(i, g(i), 1);  
  }
  
  scanf("%d", &q);
  while (q--) {
    scanf("%d %d %d", &l, &r, &k);
    printf("%d\n", sum(r, k) - sum(l - 1, k));
  }
}