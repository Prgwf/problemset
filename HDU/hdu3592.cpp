#include <bits/stdc++.h>
using namespace std;
#define lson o<<1
#define rson o<<1|1
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int N = 100000 + 20;
const int INF = 0x3f3f3f3f;

vector<pair<int,int>> G[N];
void add_edge(int x, int y, int w) {
  G[x].push_back({y, w});
}
int SPFA(int n, int start) {
  vector<bool> inq(n + 1, false);
  vector<int> d(n + 1, INF);
  vector<int> cnt(n + 1, 0);
  d[start] = 0;
  queue<int> Q;
  Q.push(start);
  inq[start] = true;

  int flag = 0;
  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();
    inq[x] = false;
    if (++cnt[x] > n + 1) {
      flag = 1;
      break;
    }

    for (const auto & pii : G[x]) {
      int v = pii.first;
      int w = pii.second;
      if (d[v] > d[x] + w) {
        d[v] = d[x] + w;
        if (!inq[v]) {
          Q.push(v);
          inq[v] = true;
        }
      }
    }
  }
  int ans;
  if (flag) ans = -1;
  else if (d[n] == INF) ans = -2;
  else ans = d[n];
  return ans;
}
int main(int args, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  int T;
  scanf("%d", &T);
  while (T--) {
    int n, nx, ny;
    scanf("%d %d %d", &n, &nx, &ny);
    for (int i = 1; i <=n; ++i) {
      G[i].clear();
    }
    int a, b, c;
    for (int i = 0; i < nx; ++i) {
      scanf("%d %d %d", &a, &b, &c);
      add_edge(a, b, c);
    }
    for (int i = 0; i < ny; ++i) {
      scanf("%d %d %d", &a, &b, &c);
      add_edge(b, a, -c);
    }
    for (int i = 1; i + 1<= n; ++i) {
      add_edge(i + 1, i, -1);
    }
    printf("%d\n", SPFA(n, 1));
  }
  return 0;
}
