/*
教练我想打ACM～
*/
#include <stdio.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;


ll mod_pow(ll a, ll b, int moder) {
  ll ret = 1LL, base = a;
  while (b) {
    if (b & 1) {
      ret = ret * base % moder;
    } 
    base = base * base % moder;
    b >>= 1;
  }
  return ret;
}

int main() {
  int T;
  scanf("%d", &T);

  int kase = 0;
  while (T--) {
    int a, p;
    scanf("%d%d", &a, &p);

    int t = mod_pow(a, (p - 1) / 2, p);
    t = (t + p) % p;
    if (t > 1) t -= p;
    printf("Scenario #%d:\n%d\n\n", ++kase, t);
  }
}
