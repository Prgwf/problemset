#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, a[N];
char s[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  scanf("%s", s);
  s[n - 1] = '0';

  int l, r;
  l = r = -1;
  for (int i = 0; i < n; ++i) {
    int k = s[i] - '0';
    if (k) {
      if (l != -1) r++;
      else l = r = i;
    } else {
      if (l >= 0 && r >= 0) sort(a + l, a + r + 1 + 1);
      l = r = -1;
    } 
  }
  bool flag = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] < a[i - 1]) {
      flag = 0; break;
    }
  }
  printf("%s", flag ? "YES" : "NO");
}
