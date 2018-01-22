/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int moder = 1e9 + 7;

int main() {
  ll power2[100];
  power2[0] = 1;
  for (int i = 1; i <= 62; ++i) {
    power2[i] = power2[i - 1] * 2LL;
  }
  
  ll n;
  int k;
  scanf("%lld%d", &n, &k);

  int cnt = __builtin_popcountll(n);
  if (cnt > k) {
    cout << "No";
    return 0;
  }

  cout << "Yes" << endl;
  if (cnt == k) {
    for (ll i = 62; ~i; --i) {
      if (n >> i & 1) {
        cout << i << " ";
      }
    }
  } else {
    multiset<int, greater<int>> Set;
    for (ll i = 62; ~i; --i) {
      if (n >> i & 1) {
        Set.insert(i);
      }
    }
    int left = k - cnt;
    while (left) {
      int T = *Set.begin();
      Set.erase(Set.begin());
      Set.insert(T - 1);
      Set.insert(T - 1);
      left--;
    }
    for (int x : Set) {
      cout << x << " ";
    }
  }
}
