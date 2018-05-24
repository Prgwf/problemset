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

const int N = 2000000 + 20;
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
  ++sz;
}
void sa_extend(int c) {
  int cur = sz++;
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
int n;
string str;
int main(int args, char const *agrv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> str;
  str = str + str;
  string rev(str.rbegin(), str.rend());
  str.push_back('z' + 1);
  str = str + rev;
  int k = n;
  n = str.size();
  
  ll ans = 0;
  sa_init();
  for (int i = 0; i < n; ++i) sa_extend(str[i] - 'a');
  for (int x = 0; x < sz; ++x) {
    if (st[x].link < 0) continue;
    if (st[st[x].link].len > k) continue;
    ans += 1LL * min(k, st[x].len) - 1LL * st[st[x].link].len;
  }
  for (int i = 1; i <= k; ++i) ans -= i;
  cout << ans;
  return 0;
}



