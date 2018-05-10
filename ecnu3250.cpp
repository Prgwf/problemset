#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;

int n, k;
int val[N];
vector<int> a[N];
int main(int args, char const *argv[]) {
  for (int i = 1; i <= 1000000; ++i) {
    for (int j = i; j <= 1000000; j += i) {
      a[j].push_back(i);
    }
  }

  int T;
  scanf("%d",  &T);
  int kase = 0;
  while (T--) {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", val + i);
    vector<int> ans;
    for (int i = 1; i < n; ++i) {
      int g = __gcd(val[i], val[i + 1]);
      if (a[g].size() < k) {
        ans.push_back(-1);
        continue;
      }
      ans.push_back(g / a[g][k - 1]);
    }
    printf("Case %d:", ++kase);
    for (int & x : ans) printf(" %d", x);
    puts("");
  }
}
