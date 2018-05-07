#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 200000 + 20;
const int INF = 0x3f3f3f3f;

int a[N];
int main(int args, char const *argv[]) {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);

  sort(a, a + n);

  if (k == 0) {
    if (a[0] <= 1) {
      printf("-1");
    } else {
      printf("1");
    }
    return 0;
  }


  if (a[k] == a[k - 1]) {
    printf("-1");
    return 0;
  }
  printf("%d\n", a[k - 1]);
}
