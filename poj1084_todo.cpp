#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
#if defined(_WIN32)
#define lld I64d
#endif

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;

int n, k;
vector<int> token;
int main(int args, char const *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &k);
    token.clear();
    for (int i = 0; i < k; ++i) {
      int x;
      scanf("%d", &x);
      token.push_back(x);
    }

  }
}
