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
struct edge {
  int from, to, cap, flow;
  edge(int u, int v, int c, int f) 
    : from(u), to(v), cap(c), flow(f) {

    }
} ;

struct EK {
  vector<edge> edges;
  vector<vector<int> > G;
  int n, m;
  int a[maxn];
  int p[maxn];

  void init(int n) {
    this->n = n;
    G.resize(n + 5);
  }

  void add_edge(int from, int to, int cap, int flow) {
    edges.push_back(edge(from, to, cap, 0));
    edges.push_back(edge(to, from, 0, 0));
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }
  
  int run(int s, int t) {
    int flow = 0;

    while (true) {
      memset(a, 0, sizeof(a));
      queue<int> Q;
      Q.push(s);
      a[s] = INF;
      
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
        edges[p[v]].flow += flow;
        edges[p[v] ^ 1].flow -= flow;
      }
      flow += a[t];
    }
    return flow;
  }  
} ;
int main(int argc, char const *argv[])
{
  // freopen("data.in", "r", stdin);
  
  return 0;
}