#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 300 + 20;
const int INF = 0x3f3f3f3f;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<string> S(n);
  for (auto && s : S) {
    cin >> s;
  }

  int ans = 0;
  for (int k = 0; k < n; ++k) {
    int ok = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <  n; ++j) {
        int ii = (i + k) % n;
        int jj = (j - k + n) % n;
        ok &= (S[i][j] == S[jj][ii]);
      }
    }
    if (ok) ans++;
  }

  cout << ans * n << endl;
}
