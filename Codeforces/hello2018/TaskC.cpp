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

  const ll llinf = 1e18;
  void work(istream &in, ostream &out) {
    int n, L;
    in >> n >> L;

    vector<ll> c;
    c.resize(32, llinf);

    for (int i = 0; i < n; ++i) {
      in >> c[i];
    }


    for (int i = 30; i >= n; --i) {
      for (int j = 0; j < n; ++j) {
        c[i] = min(c[i], c[j] * (1LL << (i - j)));
      }
    }
    for (int i = 0; i <= 30; ++i) {
      for (int j = 0; j < i; ++j) {
        c[i] = min(c[i], c[j] * (1LL << (i -j)));
      }
      for (int j = i + 1; j <= 30; ++j) {
        c[i] = min(c[i], c[j]);
      }
    }


    vector<ll> dp[2];
    dp[0].assign(32, 0);
    dp[1].assign(32, 0);

    ll ans = llinf;
    int lowbit = 0;
    for (int i = 0; i <= 30; ++i) {
      if (L >> i & 1) {
        lowbit = i;
        break;
      }
    }
    for (int i = 30; i > lowbit; --i) {
      if (L >> i & 1) {
        if (dp[0][i + 1] != -1) {
          ans = min(ans, dp[0][i + 1] + c[i] * 2LL);  
          dp[1][i] = dp[0][i + 1] + c[i];
        } else {
          ans = min(ans, dp[1][i + 1] + c[i] * 2LL);
          dp[1][i] = dp[1][i + 1] + c[i];
        }
        dp[0][i] = -1;
      } else {
        if (dp[0][i + 1] != -1) {
          ans = min(ans, dp[0][i + 1] + c[i]);
          dp[0][i] = dp[0][i + 1];
        } else {
          ans = min(ans, dp[1][i + 1] + c[i]);
          dp[0][i] = dp[1][i + 1];
        }
        dp[1][i] = -1;
      }
    }
    if (dp[0][lowbit + 1] != -1) {
      ans = min(ans, dp[0][lowbit + 1] + c[lowbit]);
    } else {
      ans = min(ans, dp[1][lowbit + 1] + c[lowbit]);
    }

    out << ans;
  } 

} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work(cin, cout);
}

