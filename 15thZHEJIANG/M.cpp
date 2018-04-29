#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;

int n, a[N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int b;
    scanf("%d %d", &n, &b);
    int flag = 0;
    for (int i = 0; i < n; ++i) {
      int x;scanf("%d", &x);
      if ((x + b) % 7 == 0) {
        flag = 1;
      }
    }
    printf("%s\n", flag ? "Yes" : "No");
  }
}
