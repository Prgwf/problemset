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

struct state {
  int len, link;
  map<char, int> next;
} ;
state st[N * 2];
int sz, last;
void sa_init() {
  sz = last = 0;
  st[0].len = 0;
  st[0].link = -1;
  st[0].next.clear();
  ++sz;
}
void sa_extend(int c) {
  int cur = sz++;
  st[cur].next.clear();
  st[cur].len = st[last].len + 1;
  int p;
  for (p = last; p != -1 && !st[p].next.count(c); p = st[p].link) {
    st[p].next[c] = cur;
  }
  if (p == -1) {
    st[cur].link = 0;
  } else {
    int q = st[p].next[c];
    if (st[p].len + 1 == st[q].len) {
      st[cur].link = q;
    } else {
      int clone = sz++;
      st[clone].len = st[p].len + 1;
      st[clone].next = st[q].next;
      st[clone].link = st[q].link;
      for (; p != -1 && st[p].next[c] == q; p = st[p].link) {
        st[p].next[c] = clone;
      }
      st[q].link = st[cur].link = clone;
    }
  }
  last = cur;
}
char s[N];
int main(int args, char const *agrv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    sa_init();
    for (int i = 0; s[i]; ++i) sa_extend(s[i]);
    ll ans = 0;
    for (int i = 0; i < sz; ++i) {
      ans += 1LL * (st[i].len - st[st[i].link].len);
    }
    printf("%lld\n", ans);
  }
  return 0;
}