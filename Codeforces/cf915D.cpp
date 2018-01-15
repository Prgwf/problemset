/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int moder = 1e9 + 7;

vector<vector<int>> g;
vector<int> deg;
vector<int> tdeg;

bool sorted() {
  vector<int> Q;
  for (int i = 0; i < (int)tdeg.size(); ++i) {
    if (tdeg[i] <= 0) {
      Q.push_back(i);
    }
  }

  while (!Q.empty()) {
    int x = Q.back();
    Q.resize(Q.size() - 1);

    for (int v : g[x]) {
      tdeg[v]--; 
      if (!tdeg[v]) {
        Q.push_back(v);
      }
    }
  }

  for (int i = 0; i < (int)tdeg.size(); ++ i) {
    if (tdeg[i] > 0) {
      return false;
    }
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  g.assign(n, vector<int>());
  deg.assign(n, 0);

  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    deg[y]++;
  }

  for (int i = 0; i < n; ++i) {
    tdeg = deg;
    tdeg[i]--;

    if (sorted()) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  
}
