#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {
  ll res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int maxn = 2000 + 20;
const int INF = 0x3f3f3f3f;
struct Edge {
  int from, to, cap, flow;
  Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};
struct EdmondsKarp {
  int n, m;
  vector<Edge> edges;  // 边数的两倍
  vector<int> G[maxn];
  int a[maxn];  // 当前起点到i的可改进量
  int p[maxn];  // 最短路树上p的入弧编号

  void init(int n) {
    for (int i = 0; i <= n; ++i) G[i].clear();
    edges.clear();
  }

  void add_edge(int from, int to, int cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }

  int Maxflow(int s, int t) {
    int flow = 0;
    for (;;) {
      memset(a, 0, sizeof(a));
      queue<int> Q;
      Q.push(s);
      a[s] = INF;
      while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        for (int i = 0; i < (int)G[x].size(); i++) {
          Edge& e = edges[G[x][i]];
          if (!a[e.to] && e.cap > e.flow) {
            p[e.to] = G[x][i];
            a[e.to] = min(a[x], e.cap - e.flow);
            Q.push(e.to);
          }
        }
        if (a[t]) break;
      }
      if (!a[t]) break;
      for (int u = t; u != s; u = edges[p[u]].from) {
        edges[p[u]].flow += a[t];
        edges[p[u] ^ 1].flow -= a[t];
      }
      flow += a[t];
    }
    return flow;
  }

} max_flow;

int main(int argc, char const* argv[]) {
  // freopen("data.in", "r", stdin);
  int n, m;
  scanf("%d %d", &n, &m);
  max_flow.init(n);
  for (int i = 0; i < m; ++i) {
    int x, y, c;
    scanf("%d %d %d", &x, &y, &c);
    max_flow.add_edge(x - 1, y - 1, c);
  }

  printf("%d\n", max_flow.Maxflow(0, n - 1));
  return 0;
}