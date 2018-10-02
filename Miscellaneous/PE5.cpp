#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll lcm(ll a, ll b) {
  return a / __gcd(a, b) * b;
}
int main() {
  ll ans = 1LL;
  for (int i = 2; i <= 20; ++i) ans = lcm(ans, i);
  printf("%lld\n", ans);  
}