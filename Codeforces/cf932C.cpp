#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

#define mod(a, b) (((a) % (b) + (b)) % (b))
const int N = 1e6 + 5;

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
  if (b == 0) {
    x = 1; y = 0;
    return a;
  }  
  i64 d = exgcd(b, a % b, x, y);
  i64 t = x; x = y; y = t - a / b * y;
  return d;
}

bool check(i64 a, i64 b, i64 n, i64 &x, i64 &y) {
  if (not a and not b) return 0;
  
  i64 x0, y0, dx, dy;
  i64 g = exgcd(a, b, x0, y0);
  
  if (n % g) return 0;
  
  dx = b / g; dy = a / g;
  x =  mod(x0 * n / g, dx);
  y = (n - a * x) / b;
  return 1;
}

int n, a, b;

int main() {
  scanf("%d %d %d", &n, &a, &b);
  if (a > b) swap(a, b);

  i64 x, y;
  if (not check(a, b, n, x, y) or y < 0) {
    puts("-1");
    return 0;
  }

  vector<int> perm;
  int i = 1;
  while (x--) {
    int t = a;
    int r = i++;
    while (t--) {
      if (not t) perm.push_back(r);
      else perm.push_back(i++);
    }
  }

  while (y--) {
    int t = b;
    int r = i++;
    while (t--) {
      if (not t) perm.push_back(r);
      else perm.push_back(i++);
    }
  }

  for (int i : perm) printf("%d ", i);
  printf("\n");
}