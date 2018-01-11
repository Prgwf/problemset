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

  vector<int> dp;
  void work() {
    int T;
    cin >> T;

    while (T--) {
      int n, t;
      cin >> n >> t;

      dp.assign(t + 1, 0);
      for (int i = 0; i < n; ++i) {
        int w1, t1, w2, t2;
        cin >> w1 >> t1 >> w2 >> t2;
        
        for (int v = t; v >= min(t1, t2); --v) {
          if (v >= t1) {
            dp[v] = max(dp[v], dp[v - t1] + w1);
          }
          if (v >= t2) {
            dp[v] = max(dp[v], dp[v - t2] + w2);
          }
        }
      }
      cout << dp[t] << endl;
    }
  }

} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work();
}

