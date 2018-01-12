/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int moder = 1e9 + 7;

struct Solution {
  vector<int> c;
  int up;
  void add(int x, int k) {
    while (x <= up) {
      c[x] += k;
      x += x & (-x);
    }
  }

  int sum(int x) {
    int ret = 0;
    while (x) {
      ret += c[x];
      x -= x & (-x);
    }
    return ret;
  }

  void work() {
    int T;
    scanf("%d", &T);

    int kase = 0;
    while (T--) {
      int n;
      scanf("%d", &n);
      vector<int> a, b;
      a.resize(n);      
      
      for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
      }

      b = a;
      sort(b.begin(), b.end());
      b.erase(unique(b.begin(), b.end()), b.end());
      up = b.size();
      for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
      }

      int ans = 0;
      c.assign(n + 5, 0);
      reverse(a.begin(), a.end());
      for (int x : a) {
        ans += sum(x - 1);
        add(x, 1);
      }
      printf("Scenario #%d:\n%d\n", ++kase, ans);
      puts("");
    }

  }

} ; 
Solution Woo;
int main() {
  Woo.work();
}

