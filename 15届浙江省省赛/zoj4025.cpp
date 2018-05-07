#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;

int T;
int n, a[N], b[N];
map<int, int> cnt;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    cnt.clear();
    for (int i = 0; i < n; ++i) {
      scanf("%d", b + i);
      a[i] -= b[i];
      cnt[a[i]]++;
    }
    int ans = -1;
    for (const auto & kv : cnt) {
      ans = max(ans, kv.second);
    }
    printf("%d\n",ans);
  }
}
