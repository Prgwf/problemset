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
  const ll up = 1e18;
  vector<ll> p{2, 3, 5};
  vector<ll> a;

  void dfs(int i, ll x) {
    if (i == (int)p.size()) {
      a.push_back(x);
      return;
    }

    dfs(i + 1, x);

    while (x <= up / p[i]) {
      dfs(i + 1, x *= p[i]);
    }
  }

  void work() {
    int T;
    scanf("%d", &T);

    dfs(0, 1LL);
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    a.pop_back();
    reverse(a.begin(), a.end());

    while (T--) {
      ll n;
      scanf("%lld", &n);


      vector<ll> ans;
      ans.push_back(*lower_bound(a.begin(), a.end(), n));
      for (ll & x : ans) {
        printf("%lld\n", x);
      }
    }
  }
} ; 
Solution Woo;
int main() {
  Woo.work();
}

