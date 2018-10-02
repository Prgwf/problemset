/*
教练我想打ACM~
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 10000 + 20;

int n, m;
vector<tuple<int, int, ll>> edges, tedges;
int a, b, ans;
int fa[maxn];
void init() {
  for (int i = 1; i <= n; ++i) {
    fa[i] = i;
  }
}
int find(int x) {
  if (x != fa[x]) {
    fa[x] = find(fa[x]);
  }
  return fa[x];
}

int main() {
  scanf("%d%d", &n, &m);

  init();
  for (int i = 0; i < m; ++i) {
    int u, v;
    ll w;
    scanf("%d%d%lld", &u, &v, &w);
    edges.emplace_back(u, v, w);
    fa[find(u)] = find(v);
  }

  scanf("%d%d", &a, &b);
  if (find(a) != find(b)) {
    puts("-1");
    return 0;
  }

  ll ans = (1LL << 62) - 1LL;
  for (ll i = 61; ~i; --i) {
    tedges.clear();
    m = edges.size();
    for (int j = 0; j < m; ++j) {
      int u, v;
      ll w;
      tie(u, v, w) = edges[j];
      // cerr << u << " " << v << " " <<  w << endl;
      if (!(w >> i & 1)) {
        tedges.emplace_back(u, v, w);
      }
    }

    init();
    for (auto T : tedges) {
      int u, v;
      ll w;
      tie(u, v, w) = T;
      fa[find(u)] = find(v);
    }

    if (find(a) == find(b)) {
      edges = tedges;
      ans ^= (1LL << i);
    }
  }
  printf("%lld\n", ans);
}
