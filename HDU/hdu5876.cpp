#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int inf = 0x3f3f3f3f;

int T, n, m, s;
vector<unordered_set<int>> g;
set<int> st, ts;
vector<int> ans;
void solve() {
  ans.assign(n + 2, inf);
  st.clear(); ts.clear();
  for (int i = 1; i <= n; ++i) {
    st.insert(i);
  }
  st.erase(s);
  queue<int> Q;
  Q.push(s);
  ans[s] = 0;

  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int v : g[u]) {
      if (!st.count(v)) continue;
      st.erase(v);
      ts.insert(v);
    }
    for (int v : st) {
      ans[v] = ans[u] + 1;
      Q.push(v);
    }
    swap(st, ts);
    ts.clear();
  }
}

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &m);
    g.clear();
    g.resize(n + 2);
    for (int i = 0; i < m; ++i) {
      int x, y;
      scanf("%d %d", &x, &y);
      g[x].insert(y);
      g[y].insert(x);
    }
    scanf("%d", &s);

    solve();
    for (int i = 1; i <= n; ++i) if (i != s) {
      if (ans[i] >= inf) ans[i] = -1;
      printf("%d%c", ans[i], i < n ? ' ' : '\n'); 
    }
  }  
}