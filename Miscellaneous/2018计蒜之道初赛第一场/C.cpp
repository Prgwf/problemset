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

int n, m;
vector<int> G[N];
vector<int> rG[N];
vector<int> nG[N];
vector< pair< int, int > > edges;
vector<int> vs;
bool vis[N];
int sccno[N], scc_tot;
int ideg[N], odeg[N];
ll cost[N];
int a[N], pos[N];
void init() {
  for (int i = 1; i <= n; ++i) {
    G[i].clear();
    rG[i].clear();
    nG[i].clear();
  }
  edges.clear();
}
void add_edge(int from, int to) {
  G[from].push_back(to);
  rG[to].push_back(from);
  edges.push_back({from, to});
}
void DFS(int x) {
  vis[x] = true;
  for (int i = 0; i < G[x].size(); ++i) {
    if (!vis[G[x][i]]) DFS(G[x][i]);
  }
  vs.push_back(x);
}
void rDFS(int x, int k) {
  vis[x] = true;
  sccno[x] = k;
  cost[k] += a[x];
  for (int i = 0; i < rG[x].size(); ++i) {
    if (!vis[rG[x][i]]) rDFS(rG[x][i], k);
  }
}
void scc() {
  memset(vis, 0, sizeof(vis));
  vs.clear();
  for (int v = 1; v <= n; ++v) {
    if (!vis[v]) DFS(v);
  }
  memset(vis, 0, sizeof(vis));
  int k = 0;
  for (vector<int>::reverse_iterator it = vs.rbegin(); it != vs.rend(); ++it){
    if (!vis[*it]) rDFS(*it, k++);
  }
  scc_tot = k;
}
void run() {
  memset(ideg, 0, sizeof(ideg));
  memset(odeg, 0, sizeof(odeg));
  // map 去重看情况
  map< pair< int, int >, bool > S;
  for (int i = 0; i < edges.size(); ++i) {
    int u = sccno[edges[i].first];
    int v = sccno[edges[i].second];
    if (u != v) {
      if (S.count(make_pair(u, v))) continue;
      S[make_pair(u, v)] = 1;
      ++odeg[u]; ++ideg[v];
      nG[u].push_back(v);
    }
  }
}
int main(int args, char const *argv[]) {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    pos[i] = i;
  }
  scanf("%d", &m);
  while (m--) {
    int opt, x, y, k;
    scanf("%d", &opt);
    if (opt) {
      scanf("%d %d %d", &k, &x, &y);
      for (int i = x; i <= y; ++i) {
        add_edge(pos[k], pos[i]);
      }
    } else {
      scanf("%d %d", &k, &x);
      a[++n] = x;
      pos[k] = n;
    }
  }
  scc();
  run();
  ll ans = 4e18;
  for(int i = 0; i < scc_tot; ++i) {
    // printf("cost[%d]=%lld\n", i, cost[i]);
    if (odeg[i] == 0) {
      ans = min(ans, cost[i]);
    }
  }
  printf("%lld\n", ans);
}
