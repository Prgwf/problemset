#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100 + 20;
const int INF = 0x3f3f3f3f;

char a[N], b[N];
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  while (scanf("%s", a) != EOF) {
    int n = strlen(a);
    scanf("%s", b);
    map<char, int> has;
    for (int i = 0; i < n; ++i) has[b[i]]++;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int pt = a[i] - 'A';
      for (int j = 0; j < 26; ++j) {
        char k = 'A' + ((pt + j) % 26);
        if (has.count(k)) {
          // printf("a->%c, b->%c\n", a[i], k);
          if (k >= a[i]) {ans += k - a[i];}
          else {ans += 26 - (a[i] - k);}

          if (!--has[k]) has.erase(k);
          break;
        }
      }
    }
    printf("%d\n", ans);
  }
}
