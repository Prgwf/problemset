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
  int w, z, a, b;
  vector<int> dp;

  int dfs(int x) {
    if (x > w) {
      return 0;
    }
    if (x == w) {
      return 1;
    }
    if (dp[x]) return dp[x];

    return dp[x] = dfs(x + a) + dfs(x + b);

  }
  void work() {
    int T;
    cin >> T;

    while (T--) {
      cin >> w >> z;
      cin >> a >> b;
      dp.assign(w + 1, 0);

      dp[w] = 1;
      dfs(z);

      cout << dp[z] << endl;
    }

  }

} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work();
}

