#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int N = 200000 + 7;

int n;
vector<vector<int>> T;
int deg[N];
vector<int> ret;
void dfs(int x, int p) {
  for (int v : T[x]) {
    if (v == p) continue;
    
    dfs(v, x);
  }
}

int main() {
  cin >> n;
  T.resize(n, vector<int>());
  if (n & 1) {
    cout << "YES";
    int u;
    for (int i = 1; i <= n; ++i) {
      int p;
      cin >> p;
      if (p) {
        T[i].push_back(p);
        T[p].push_back(i);
        deg[i]++;
        deg[p]++;
      } else {
        u = i;
      }
    }
    dfs(u, -1);
  } else {
    cout << "NO";
  }
}
