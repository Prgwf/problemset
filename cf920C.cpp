#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n;
int a[N];
char s[N];
int T[N];

void add(int x, int k) {
  while (x <= n) {
    T[x] += k;
    x += x & -x;
  }
}

int sum(int x) {
  int ret = 0;
  while (x) {
    ret += T[x];
    x -= x & -x;
  }
  return ret > 0;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  scanf("%s", s + 1);
  
  int flag = 1;
  for (int i = n; i; --i) {
    int u = s[i] - '0';
    int v = sum(a[i] - 1);
    add(a[i], 1);
    if (v == 1 && u == 0) {
      flag = 0;
      break;
    }
  }
  printf("%s", flag ? "YES" : "NO");
}