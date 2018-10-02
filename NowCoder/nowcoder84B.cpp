#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;

int n, a[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  int mid = (n & 1) ? (n + 1) / 2 : n / 2;

  map<int, int> cnt;
  for (int i = 1; i <= mid; ++i) {
    a[i] -= i;
  }
  for (int i = n, j = 1; i > mid; --i, ++j) {
    a[i] -= j;
  }
  for (int i = 1; i <= n; ++i) {
    cnt[a[i]]++;
  }

  int ans = 0;
  for (const auto & kv : cnt) {
    ans = max(ans, kv.second);
  }
  printf("%d\n", n - ans);
}
