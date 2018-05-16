#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;
const int maxbit = 20;

int n, ans, limit;
struct Trie {
  int min;
  Trie *s[2];
  Trie() {
    min = INF;
    s[0] = s[1] = nullptr;
  }
} *T[N];
void ins(Trie *o, int b, int x) {
  o->min = min(o->min, x);
  if (b < 0) {
    return;
  }
  int d = x >> b & 1;
  if (o->s[d] == nullptr) o->s[d] = new Trie();
  ins(o->s[d], b - 1, x);
}
void qry(Trie *o, int b, int x, int y) {
  if (b < 0) {
    assert(y <= limit);
    ans = max(ans, y ^ x);
    return;
  }
  int d = x >> b & 1;
  for (int i = 1; i >= 0; --i) {
    int k = d ^ i;
    if (o->s[k] && o->s[k]->min <= limit) {
      qry(o->s[k], b - 1, x, (y | (k << b)));
      return;
    }
  }
}
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  scanf("%d", &n);

  for (int i = 1; i <= 100000; ++i) T[i] = new Trie();
  for (int i = 1; i <= n; ++i) {
    int opt, x, k, s;
    scanf("%d", &opt);
    if (opt == 1) {
      scanf("%d", &x);
      for (int j = 1; j * j <= x; ++j) {
        if (x % j) continue;
        ins(T[j], maxbit, x);
        if (j * j != x) ins(T[x / j], maxbit, x);
      }
    }
    if (opt == 2) {
      scanf("%d %d %d", &x, &k, &s);
      if (x % k) {
        printf("%d\n", -1);
        continue;
      }
      ans = -1, limit = s - x;
      qry(T[k], maxbit, x, 0);
      if (ans != -1) ans ^= x;
      printf("%d\n", ans);
    }
  }
}
