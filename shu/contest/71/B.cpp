/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 20;
const int moder = 1e9 + 7;

struct Solution {
   
  void work(istream &in, ostream &out) { 
    string init;
    getline(in, init);

    int x;
    stringstream ss(init);
    vector<int> a;
    while (ss >> x) {
      a.push_back(x);
    }

    reverse(a.begin(), a.end());
    int n = a.size();
    vector<int> dp(n, 1);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (a[j] <= a[i]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      ans = max(ans, dp[i]);
    }
    out << ans << endl;

    reverse(a.begin(), a.end());
    dp.assign(n, 0);
    ans = 0;
    for (int i = 0; i < n; ++i) {
      int idx = lower_bound(dp.begin(), dp.begin() + ans, a[i]) - dp.begin();
      if (idx == ans) {
        dp[ans++] = a[i];
      } else {
        dp[idx] = a[i];
      }
    }
    out << ans << endl;
  } 

} ; 
Solution Woo;
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work(cin, cout);
}

