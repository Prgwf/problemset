#include <bits/stdc++.h>
using namespace std;
#define lson o<<1
#define rson o<<1|1
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const ll INF = 4e15;

int n, f[N], lb[N], ub[N];
int pos[N];
vector<pair<int, int>> G[N];
void add_edge(int x, int y, int w) {
  G[x].emplace_back(y, w);
}
int SPFA(int n, int start,vector<ll> & d) {
  d.assign(n + 1, INF);
  vector<bool> inq(n + 1, false);
  vector<int> cnt(n + 1, 0);

  queue<int> Q;
  Q.push(start);
  inq[start] = true; d[start] = 0;

  int ans = 0;
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    inq[u] = false;
    if (++cnt[u] > n + 1) {
      ans = -1;
      break;
    }

    for (const auto & pii : G[u]) {
      int v = pii.first;
      ll w = 1LL * pii.second;
      if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
        if (!inq[v]) {
          Q.push(v);
          inq[v] = true;
        }
      }
    }
  }

  if (ans != -1) ans = d[n];
  return ans;
}
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n + 1; ++i) G[i].clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", f + i);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d %d", lb + i, ub + i);
    }
    int S = n + 1;
    memset(pos, 0, sizeof(pos));
    for (int i = 1; i <= n; ++i) {
      add_edge(i, S, -lb[i]);
      add_edge(S, i, ub[i]);
      if (pos[f[i] - 1]) {
        add_edge(i, pos[f[i] - 1], -1);
      }
      if (pos[f[i]]) {
        add_edge(pos[f[i]], i, 0);
      }
      pos[f[i]] = i;
    }

    vector<ll> ans;
    SPFA(n + 1, S, ans);
    for (int i = 1; i <= n; ++i) {
      printf("%lld%c", ans[i], (i < n) ? ' ':'\n');
    }
  }
}
