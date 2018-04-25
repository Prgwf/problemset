#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<limits.h>
#include<assert.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1; a%=mod; assert(b> 0); for (;b;b>>=1) {if (b&1) res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int INF = 0x3f3f3f3f;
const int N = 3000 + 20;
struct edge {
  int from, to, cap, flow;
  edge(int u, int v, int c, int f) 
    :from(u), to(v), cap(c), flow(f) {

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
    G.assign(n + 5, vector<int>());
    edges.clear();
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

int M[N];
int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  int cas;
  scanf("%d", &cas);

  while (cas--) {
    int n, m;
    scanf("%d %d", &n, &m);

    max_flow.init(n + m + 2);
    int S = 0, T = n + m + 2;
    int sum = 0;
    for (int i = 1; i <= m; ++i) {
      scanf("%d", M + i);
      sum += M[i];
      max_flow.add_edge(i + n, T, M[i]);
    }
    for (int u = 1; u <= n; ++u) {
      int a, k;
      scanf("%d %d", &a, &k);
      max_flow.add_edge(S, u, a);
      for (int j = 0; j < k; ++j) {
        int v; scanf("%d", &v);
        max_flow.add_edge(u, v + n, 1);
      }
    }
    int f = max_flow.run(S, T);

    printf("%s\n", f == sum ? "Yes" : "No");
  }
  return 0;
}
