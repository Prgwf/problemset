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

int n, a[N];
map<int, int> cnt;
int main(int args, char const *argv[]) {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }

  for (int i = 1; i <= n; ++i) {
    cnt[a[i]] = 1;
    if (cnt.count(a[i] - 1)) {
      cnt[a[i]] = cnt[a[i] - 1] + 1;
    }
  }

  int ans = 0;
  int t = -1;
  for (const auto & kv : cnt) {
    if (ans < kv.second) {
      ans = kv.second;
      t = kv.first;
    }
  }

  printf("%d\n", ans);
  stack<int> S;
  for (int i = n; i >= 1; --i) {
    if (a[i] == t) {
      S.push(i);
      t--;
    }
  }
  while (!S.empty()) {
    printf("%d ", S.top()); S.pop();
  }
}

/*
9
6 7 8 3 4 5 9 10 11
*/
