#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 20;
const int moder = 1LL * (1e9 + 7);

int fact[maxn];
long long mod_pow(long long x, long long b) {
  long long ret = 1;
  long long base = x;
  while (b) {
    if (b & 1) {
      ret = ret * base % moder;
    }
    base = base * base % moder;
    b >>= 1;
  }
  return ret;
}
long long inv(long long x) {
  return mod_pow(x, moder - 2);
}
void init() {
  fact[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    fact[i] = 1LL * fact[i - 1] * i;
  }
}
int main() {
  init();
  int T;
  scanf("%d", &T);
  
  while (T--) {
    long long t, p;
    scanf("%lld%lld", &t, &p);
    p = abs(p);
    if (t < p) {
      printf("%d\n", 0);
      continue;
    }
    long long ans = 0, temp;
    for (int k = 0; 2 * k <= t - p; ++k) {
      temp = fact[t];
      temp = temp * inv(fact[p + k]) % moder;
      temp = temp * inv(fact[k]) % moder;
      temp = temp * inv(fact[t - p - 2 * k]) % moder;
      temp = temp * inv(mod_pow(4, p)) % moder;
      temp = temp * inv(mod_pow(16, k)) % moder;
      temp = temp * inv(mod_pow(2, t - p - 2 * k)) % moder;
      ans = (ans + temp) % moder;
    }
    printf("%lld\n", ans);
  }
}
