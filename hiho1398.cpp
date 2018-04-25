#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const int N = 2000 + 7;

struct edge {
  int from, to, cap, flow;
  edge(int u, int v, int c, int f)
    : from(u), to(v), cap(c), flow(f) {

    }
} ;
struct EK {
  vector<edge> edges;
  vector<vector<int>> G;
  int a[N];
  int p[N];
  int n, m;
  void init(int n) {
    this->n = n;
    G.resize(n + 5);
  }

  void add_edge(int u, int v, int c) {
    edges.push_back(edge(u, v, c, 0));
    edges.push_back(edge(v, u, 0, 0));
    m = edges.size();
    G[u].push_back(m - 2);
    G[v].push_back(m - 1);
  }

  int run(int s, int t) {
    int flow = 0;

    while (true) {
      memset(a, 0, sizeof(a));
      a[s] = INF;
      queue<int> Q;
      Q.push(s);

      while (!Q.empty()) {
        int x = Q.front();
        Q.pop();

        for (int i : G[x]) {
          const edge & e = edges[i];
          int v = e.to;
          int left = e.cap - e.flow;
          if (!a[v] && left > 0) {
            a[v] = min(a[x], left);
            p[v] = i;
            Q.push(v);
          }
        }

        if (a[t]) break;
      }

      if (!a[t]) break;

      for (int v = t; v != s; v = edges[p[v]].from) {
        edges[p[v]].flow += a[t];
        edges[p[v] ^ 1].flow -= a[t];
      }
      flow += a[t];
    }
    return flow;
  }
} max_flow;

int n, m;
int cost[N];
int main() {
  scanf("%d %d", &n, &m);
  max_flow.init(n + m + 2);
  int S = 0, T = n + m + 2;
  for (int i = 1; i <= m; ++i) {
    scanf("%d", cost + i);
    max_flow.add_edge(i + n, T, cost[i]);
  }

  int ans = 0;
  for (int u = 1; u <= n; ++u) {
    int a, k;
    scanf("%d %d", &a, &k);
    ans += a;
    max_flow.add_edge(S, u, a);
    for (int j = 0; j < k; ++j) {
      int v;
      scanf("%d", &v);
      max_flow.add_edge(u, v + n, INF);
    }
  }

  int C = max_flow.run(S, T);
  ans -= C;
  printf("%d\n",ans);
}
