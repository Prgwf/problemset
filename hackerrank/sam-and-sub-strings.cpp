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
  void work(istream &in, ostream &out) {
    string x;
    in >> x;

    int n = x.size();

    /*
     * dp[i] 表示 以第i个字符结尾的子串总和
     * dp[i] = dp[i - 1] * 10 + s[i] * (i + 1)
     * ans = sigma(dp[i])
     * */
    ll ans = 0;
    ll t = 0;
    for (int i = 0; i < n; ++i) {
      t = (t * 10LL + 1LL * (i + 1) * (x[i] - '0')) % moder;
      ans = (t + ans) % moder;
    }
    out << ans << endl;
  } 
} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work(cin, cout);
}

