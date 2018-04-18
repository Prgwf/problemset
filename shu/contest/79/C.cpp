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

  void work() {
    int T;
    cin >> T;

    while (T--) {
      int V, n;
      cin >> V >> n;
      vector<int> a(n);
      vector<int> dp;
      dp.assign(V + 2, 0);

      for (int i = 0; i < n; ++i) {
        cin >> a[i];
      }

      for (int i = 0; i < n; ++i) {
        for (int j = V; j >= 0; --j) {
          if (j >= a[i]) {
            dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
          }
        }
      }
      cout << dp[V] << endl;
    }
  }

} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work();
}

