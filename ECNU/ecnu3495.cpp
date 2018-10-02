#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define lson o<<1
#define rson o<<1|1
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 1 << 22;
const int INF = 0x3f3f3f3f;

int n;
vector<vector<int>> T;
int deg[N];
int f[N];
bool dfs(int state) {
  if (f[state] != -1) return f[state];

  for (int i = 1; i <= n; ++i) {
    int s = state;
    if (deg[i] > 0 && state >> i & 1) {
      s &= ~(1 << i);
      --deg[i];
      for (int v : T[i]) {
        if (--deg[v] <= 0) {
          s &= ~(1 << v);
        }
      }
      if (!dfs(s)) {
        for (int v : T[i]) ++deg[v];
        ++deg[i];
        return f[state] = 1;
      }

      for (int v : T[i]) ++deg[v];
      ++deg[i];
    }
  }

  return f[state] = 0;
}
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  scanf("%d", &n);
  T.assign(n + 1, vector<int>());
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    T[x].push_back(y);
    T[y].push_back(x);
    deg[x]++; deg[y]++;
  }

  int state = 0;
  memset(f, -1, sizeof(f));
  for (int i = 1; i <= n; ++i) {
    if (deg[i] > 0) state |= (1 << i);
  }
  printf("%s\n", dfs(state) ? "First" : "Second");
  return 0;
}
