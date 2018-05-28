#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<limits.h>
#include<assert.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson l,m,o<<1
#define rson m+1,r,o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 10000 + 20;
const int INF = 0x3f3f3f3f;

int n, k;
vector<int> tr[N * 4];
bitset<N> b, ans;
void update(int ll, int rr, int x, int l=1, int r=n, int o=1) {
  if (ll <= l && r <= rr) {
    tr[o].push_back(x);
    return;
  }
  int m = (l + r) / 2;
  if (ll <= m) update(ll, rr, x, lson);
  if (rr > m) update(ll, rr, x, rson);
}
void query(int l, int r, int o, bitset<N> b) {
  for (int x : tr[o]) {
    b |= (b << x);
  }
  if (l == r) {
    ans |= b;
    return;
  }
  int m = (l + r) / 2;
  query(lson, b);
  query(rson, b);
}
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  scanf("%d %d", &n, &k);
  for (int i = 0; i < k; ++i) {
    int l, r, x;
    scanf("%d %d %d", &l, &r, &x);
    update(l, r, x);
  }
  b.set(0);
  query(1, n, 1, b);
  int cnt = 0;
  for (int i = 1; i <= n; ++i) if (ans[i]) cnt++;
  printf("%d\n", cnt);
  for (int i = 1; i <= n; ++i) if (ans[i]) {
    printf("%d ", i);
  }
  return 0;
}