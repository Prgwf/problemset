#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int M = 20 + 2;
const int INF = 0x3f3f3f3f;

int n, a[N];
int pos[N][M];
int vis[1 << M];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    a[i] = x;
    vis[x] = true;
  }

  memset(pos, -1, sizeof(pos));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < M; ++j) {
      pos[i][j] = pos[i + 1][j];
    }
    for (int j = 0; j < M; ++j) {
      if (a[i] >> j & 1) pos[i][j] = i;
    }
  }
  for (int i = 0; i < n; ++i) {
    int x = 0, tx;
    for (int k = i; k < n; k = tx) {
      tx = n;
      for (int j = 0; j < M; ++j) {
        if (!(x >> j & 1) && pos[k][j] >= 0) {
          tx = min(tx, pos[k][j]);
        }
      }
      if (tx < n) {
        x |= a[tx];
        vis[x] = true;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < (1 << M); ++i) {
    if (vis[i]) ans++;
  }
  printf("%d", ans);
}
