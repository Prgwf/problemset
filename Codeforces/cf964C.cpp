#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int N = 100000 + 7;
const int mod = 1e9 + 9;

ll mod_pow(ll x, ll n) {
  x = (x + mod) % mod;
  ll ret = 1LL;
  while (n) {
    if (n & 1) ret = ret * x % mod;

    x = x * x % mod;
    n >>= 1;
  }
  return ret;
}

ll mod_inv(ll x) {
  return mod_pow(x, mod - 2);
}

ll n, a, b, k;
string line;
int main() {
  cin >> n >> a >> b >> k;
  cin >> line;

  ll q = mod_inv(mod_pow(a, k)) * mod_pow(b, k) % mod;

  ll s = 0;
  for (int i = 0; i < k; ++i) {
    ll y = 1;
    if (line[i] == '-') y = -1;
    s = (s + (y * (mod_pow(a, n - i) * mod_pow(b, i)) % mod) % mod) % mod;
    s = (s + mod) % mod;
  }
  if (q == 1) {
    s = (s * (n + 1LL) / k) % mod;
    cout << s;
    return 0;
  }
  ll ans = s * (1LL - mod_pow(q, (n + 1) / k)) % mod;
  ans = (ans + mod) % mod;
  ans = ans * mod_inv(1LL - q) % mod;
  cout << ans;
}
