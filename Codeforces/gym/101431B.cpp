#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int INF = 0x3f3f3f3f;
#define clr(x, i) memset((x), (i), sizeof((x)))
const int maxn = 2e6 + 20;
struct SAM {
  int len[maxn * 2], link[maxn * 2], ch[maxn * 2][27];
  int size, root, last;
  void init() { size = last = 0, root = newnode(); }
  int newnode(int x = 0) {
    len[size] = x;
    link[size] = -1;
    clr(ch[size], -1);
    return size++;
  }
  void extend(int c) {
    int np = newnode(len[last] + 1);
    int p;
    for (p = last; ~p && ch[p][c] == -1; p = link[p]) ch[p][c] = np;
    if (p == -1) {
        link[np] = root;
    } else {
      int q = ch[p][c];
      if (len[p] + 1 == len[q]) {
        link[np] = q;
      } else {
        int nq = newnode(len[p] + 1);
        memcpy(ch[nq], ch[q], sizeof(ch[q]));
        link[nq] = link[q], link[q] = link[np] = nq;
        for (; ~p && ch[p][c] == q; p = link[p]) ch[p][c] = nq;
      }
    }
    last = np;
  }
  int topcnt[maxn], topsam[maxn * 2];
  void sort() { // 加入串后拓扑排序
    clr(topcnt, 0);
    for (int i = 0; i < size; i++) topcnt[len[i]]++;
    for (int i = 0; i < maxn - 1; i++) topcnt[i + 1] += topcnt[i];
    for (int i = 0; i < size; i++) topsam[--topcnt[len[i]]] = i;
  }

  ll dp[maxn * 2 + 5];
  void solve(int k) {
    sort();
    ll ans = 0;
    for (int i = size - 1; i >= 0; --i) {
      int x = topsam[i];
      if (link[x] < 0) ;
      else if (len[link[x]] > k) ;
      else {
        ans += 1LL * min(k, len[x]) - 1LL*len[link[x]];
      }
    }
    for (int i = 1; i <= k; ++i) {
      ans -= 1LL * i;
    }
    printf("%lld\n", ans);
  }
} gao;

int n;
string str;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  cin >> str;
  str = str + str;
  string rev(str.rbegin(), str.rend());
  str.push_back('z' + 1);
  str = str + rev;
  int k = n;
  n = str.size();
  gao.init();
  for (int i = 0; i < n; ++i) {
    gao.extend(str[i] - 'a');
  }
  gao.solve(k);
}
