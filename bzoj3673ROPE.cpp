#include <cstdio>
#include <cstring>
#include <assert.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 200000 + 20;
const int INF = 0x3f3f3f3f;

rope<int> *fa[N];
int n, m;
int a[N];
int k = 0, id[N];
int find(int k, int x) {
  if (fa[k]->at(x) == x) return x;
  fa[k]->replace(x, find(k, fa[k]->at(x)));
  return fa[k]->at(x);
}
int main(int args, char const *argv[]) {
  scanf("%d %d", &n, &m);
  for (int i = 0; i <= n; ++i) a[i] = i;
  fa[0] = new rope<int>(a, a + n + 1);
  for (int i = 1; i <= m; ++i) {
    int opt;
    scanf("%d", &opt);
    int x, y;
    if (opt == 1) {
      scanf("%d %d", &x, &y);
      int fx = find(k, x);
      int fy = find(k, y);
      if (fx != fy) {
        fa[i] = new rope<int> (*fa[k]);
        fa[i]->replace(fx, fy);
        k = i;
      }
    } else if (opt == 2) {
      scanf("%d", &x);
      k = id[x];
    } else if (opt == 3) {
      scanf("%d %d", &x, &y);
      int fx = find(k, x);
      int fy = find(k, y);
      if (fx == fy) {
        printf("%d\n", 1);
      } else {
        printf("%d\n", 0);
      }
    }
    id[i] = k;
  }
}
