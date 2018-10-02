#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool read(T &n){
    T x = 0, tmp = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
template <class T> inline void write(T n){
    if(n < 0){putchar('-');n = -n;}
    int len = 0,data[20];
    while(n){data[len++] = n%10;n /= 10;}
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
int n, x;
int c[1000020];
int a[1000020];
int main() {
  // freopen("data.in", "r", stdin);
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    int fi = 0, se = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (a[i] > se) {
        if (a[i] > fi) {
          c[a[i]]--;
        } else {
          c[fi]++;
        }
      }
      if (a[i] > fi) {
        se = fi;
        fi = a[i];
      } else if (a[i] > se) {
        se = a[i];
      }
    }
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
      if (c[i] > c[ans]) {
        ans = i;
      }
    }
    printf("%d\n", ans);
  }
}
