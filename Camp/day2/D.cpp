#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 4e3 + 20;

int fac[maxn];
int inv[maxn];

ll mod_pow(ll x, ll b, int p) {
  ll ret = 1, base = x;
  while (b) {
    if (b & 1) {
      ret = ret * base % p;
    }
    base = base * base % p;
    b >>= 1;
  }
  return ret;
}

ll C(int n, int r, int p) {
  ll ret = fac[n];
  ret = 1LL * ret * inv[n - r] % p;
  ret = 1LL * ret * inv[r] % p;
  return ret;
}

ll calc(int r, int n, int p) {
  return C(n + r - 1, r - 1, p);
}

void init(int p) {
  fac[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    fac[i] = 1LL * fac[i - 1] * i % p; 
  }

  inv[maxn - 1] = mod_pow(fac[maxn - 1], p - 2, p);

  for (int i = maxn - 2; i >= 0; --i) {
    inv[i] = 1LL * inv[i + 1] * (i + 1) % p;
  } 
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int x, y, p;
    scanf("%d%d%d", &x, &y, &p);

    init(p);
    int n = x + y;
    ll ans = 0;
    for (int i = n & 1; i <= y; i += 2) {
      int j = (n - i) / 2 + 1;
      ans += C(n - i, x, p) * calc(j, i, p) % p;
      ans %= p;
    }
    printf("%lld\n", ans);
  }
}
