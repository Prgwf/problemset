#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100 + 20;
const int INF = 0x3f3f3f3f;

int n, ideg[N], odeg[N];
ll a[N];
vector<vector<int>> G;
int main(int args, char const *argv[]) {
  scanf("%d", &n);
  G.resize(n + 1);
  for (int i = 1; i <= n; ++i) scanf("%lld", a + i);

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (a[i] == a[j] * 2LL) {
        odeg[j]++;
        ideg[i]++;
        G[j].push_back(i);
      }
      if (a[i] == a[j] * 3LL) {
        ideg[j]++;
        odeg[i]++;
        G[i].push_back(j);
      }
    }
  }

  int s = -1;
  for (int i = 1; i <= n; ++i) {
    if (ideg[i] == 0) {
      s = i;
      printf("%lld", a[s]);
    }
  }
  assert(s > 0);

  while (!G[s].empty()) {
    s = G[s][0];
    printf(" %lld", a[s]);
  }
}
