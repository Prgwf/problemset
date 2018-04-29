#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;

int n, a[N], b[N];
int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }

    int mxid = max_element(a, a + n) - a;

    int flag = 1;
    for (int i = mxid; i >= 1; --i) {
      if (a[i - 1] >= a[i]) {
        flag = 0;
        break;
      }
    }
    for (int i = mxid; i + 1< n; ++i) {
      if (a[i + 1] >= a[i]) {
        flag = 0;
        break;
      }
    }
    if (mxid == 0 || mxid == n - 1) flag = 0;
    printf("%s\n", flag ? "Yes" : "No");
  }
  return 0;
}
