#include <bits/stdc++.h>
using namespace std;

const int N = 100007;

char s[20000];
long long a[N][5];
int mod[] = {19260817, 1789,  131, 313, 998244353};
int main() {
  for (int i = 0; i < 5; ++i) {
    a[1][i] = 1; a[2][i] = 2;
  }
  for (int i = 0; i < 5; ++i) {
    for (int j = 3; j < N; ++j) {
      a[j][i] = (a[j - 1][i] + a[j - 2][i]) % mod[i];
    }
  }

  while (scanf("%s", s) != EOF) {
    int n = strlen(s);
    long long x[5] = {0};
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < n; ++j) {
        int k = s[j] - '0';
        x[i] = x[i] * 10LL % mod[i] + 1LL * k;
      }
    }

    int f = 0, ans = -1;
    for (int i = 1; i <= 100000 && !f; ++i) {
      f = 1;
      for (int j = 0; j < 5; ++j) {
        if (a[i][j] != x[j]) {
          f = 0;
          break;
        }
        ans = i;  break;
      }
    }
    printf("%d\n", ans);
  }
}