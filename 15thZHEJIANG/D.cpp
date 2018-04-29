#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 300 + 20;
const int INF = 0x3f3f3f3f;

int pfx[N], sfx[N];
ll value[N], dp[N][N];
int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);

  int T; cin >> T;

  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
      cin >> value[i];
    }

    vector<int> L, R;
    pfx[0] = sfx[0] = 0LL;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
        L.push_back(i);
        pfx[L.size()] = pfx[L.size() - 1] + value[i];
      }
    }
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == ')') {
        R.push_back(i);
      }
    }
    for (int i = 0; i < R.size(); ++i) {
      sfx[R.size() - i] = sfx[R.size() - i + 1] + value[R[i]];
    }

    reverse(R.begin(), R.end());

    memset(dp, -0x3f, sizeof(dp));
    for (int i = 1; i <= (int)R.size(); ++i) dp[L.size() + 1][i] = 0;
    for (int i = L.size() - 1; ~i; --i) {
      for (int j = R.size() - 1; ~j; --j) {
        if (L[i] > R[j]) break;
        ll t = sfx[j + 1] * value[L[i]] + dp[i + 1][j];
        dp[i][j] = max(dp[i][j], t);
      }
    }
    printf("%lld\n", dp[0][R.size() - 1]);
  }
  return 0;
}
