#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 1000000 + 20;
const int INF = 0x3f3f3f3f;

ll dp[N][3];
string s;
int main() {
  while (cin >> s) {
    memset(dp, 0, sizeof(dp));
    int n = s.size();
    if (s[0] == '0') {
      dp[0][0] = 1;
    } else {
      dp[0][1] = 1;
    }
    for (int i = 1; i < n; ++i) {
      if (s[i] == '0') {
        dp[i][0] = dp[i - 1][0] + 1LL;
        dp[i][1] = dp[i - 1][2];
        dp[i][2] = dp[i - 1][1];
      } else {
        dp[i][1] = dp[i - 1][0] + 1LL;
        dp[i][0] = dp[i - 1][1];
        dp[i][2] = dp[i - 1][2];
      }
    }
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += dp[i][0];
    }
    cout << sum << endl;
  }
}
