#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod_mul(ll x, ll y, ll m) {
  x %= m; y %= m;
  ll t = 0;
  while (y) {
    if (y & 1) t = (t + x) % m;
    x = (x + x) % m;
    y >>= 1;
  }
  return t;
}

ll mod_pow(ll x, ll y, ll m) {
  x %= m;
  ll t = 1LL;
  while (y) {
    if (y & 1) t = mod_mul(t, x, m);
    x = mod_mul(x, x, m);
    y >>= 1;
  }
  return t;
}

bool check(ll a, ll n, ll x, ll t) {
  ll now = mod_pow(a, x, n);
  ll pre = now;
  for (int i = 1; i <= t; ++i) {
    now = mod_mul(now, now, n);
    if (now == 1 and pre != 1 and pre != n - 1) return true;
    pre = now;
  }
  if (now != 1) return true;
  return false;
}

bool miller_rabin(ll n) {

  if (n < 2) return 0;
  if (n == 2) return 1;
  if (n % 2 == 0) return 0;
    
  ll x = n - 1, t = 0;
  while (x % 2 == 0) {
    x >>= 1; 
    t++;
  }
  for (int i = 0; i < 20; ++i) {
    if (check(rand() % (n - 1) + 1, n, x, t)) return false;
  }
  return true;
}

int p, a;
int main() {
  while (scanf("%d %d", &p, &a) != EOF) {
    if (!(a + p)) break;
    if (miller_rabin(p)) {
      puts("no");
      continue;
    }

    ll t = mod_pow(a, p, p);
    puts(t == a ? "yes" : "no");
  }
}