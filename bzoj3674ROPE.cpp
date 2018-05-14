#include <cstdio>
#include <cstring>
#include <ext/rope>
#include <assert.h>
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

int n, m;
rope<int> *fa[N];
int a[N];
int find(int k, int x) {
  if (fa[k]->at(x) == x) return x;
  fa[k]->replace(x, find(k, fa[k]->at(x)));
  return fa[k]->at(x);
}
int cnt = 0, id[N];
int main(int args, char const *argv[]) {
  scanf("%d %d" , &n, &m);

  for (int i = 0; i <= n; ++i) {
    a[i] = i;
  }
  fa[0] = new rope<int>(a, a + 1 + n);
  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    int opt;
    scanf("%d", &opt);

    int x, y;
    if (opt == 1) {
      scanf("%d %d", &x, &y);
      x ^= ans; y ^= ans;
      int fx = find(cnt, x);
      int fy = find(cnt, y);
      if (fx != fy) {
        fa[i] = new rope<int> (*fa[cnt]);
        fa[i]->replace(fx, fy);
        cnt = i;
      }
    } else if (opt == 2) {
      scanf("%d", &x);
      x ^= ans;
      cnt = id[x];
    } else if (opt == 3) {
      scanf("%d %d", &x, &y);
      x ^= ans; y ^= ans;
      if (find(cnt, x) == find(cnt, y)) {
        ans = 1;
      } else {
        ans = 0;
      }
      printf("%d\n", ans);
    }
    id[i] = cnt;
  }
}
