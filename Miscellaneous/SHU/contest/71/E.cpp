/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100 + 20;
const int moder = 1e9 + 7;

struct Solution {

  vector<int> dp[2];
  void work(istream &in, ostream &out) {
    int n;
    in >> n;
    vector<int> a;
    a.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
      in >> a[i];
    }
    

    dp[0].assign(n + 1, 1);
    for (int i = 1; i <=n; ++i) {
      for (int j = 1; j <=i; ++j) {
        if (a[j] < a[i]) {
          dp[0][i] = max(dp[0][i], dp[0][j] + 1);
        }
      }
    }

    dp[1].assign(n + 1, 1);
    for (int i = n; i >=1; --i) {
      for (int j = n; j >= i; --j) {
        if (a[j] < a[i]) {
          dp[1][i] = max(dp[1][i], dp[1][j] + 1);
        }
      }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      ans = max(ans, dp[0][i] + dp[1][i + 1] - 1);
    }
    out << n - ans << endl;
  } 

} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work(cin, cout);
}

