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
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;

int n;
int deg[N];
vector<int> d;
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    deg[x]++; deg[y]++;
  }
  int cnt = 0;
  int pos = -1;
  for (int i = 1; i <= n; ++i) {
    if (deg[i] > 2) {
      cnt++;
      pos = i;
    }
    if (deg[i] == 1) d.push_back(i);
  }
  if (cnt > 1) {
    printf("No\n");
    return 0;
  }
  printf("Yes\n");
  if (pos < 0) {
    assert(d.size() == 2);
    printf("1\n");
    printf("%d %d\n", d[0], d[1]);
  } else {
    printf("%d\n", d.size());
    for (int v : d) {
      printf("%d %d\n", pos, v);
    }
  }
  return 0;
}