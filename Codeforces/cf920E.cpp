#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int n, m;
unordered_set<int> g[N];
int vis[N];
set<int> unused;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].insert(y);
    g[y].insert(x);   
  }
  for (int i = 1; i <= n; ++i) {
    unused.insert(i);
  }
  
  vector<int> ans;
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      int cnt = 0;
      queue<int> Q;
      Q.push(i); unused.erase(i);
      
      while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        ++cnt; 
        vis[u] = true;
        vector<int> del;
        for (int v : unused) {
          if (g[u].find(v) != g[u].end()) continue;
          del.push_back(v);
          Q.push(v);
        }
        for (int j : del) unused.erase(j);
      }
      ans.push_back(cnt);
    }
  }

  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (int i : ans) printf("%d ", i);
  printf("\n");
}