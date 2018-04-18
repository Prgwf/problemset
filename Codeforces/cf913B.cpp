/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int moder = 1e9 + 7;

struct Solution {

  vector<int> T[1000 + 20];
  vector<int> sz;
  void dfs(int x) {
    sz[x] = 1;
    for (int v : T[x]) {
      dfs(v);
      sz[x] += sz[v];
    }
  }
  void work(istream &in, ostream &out) {
    int n;
    in >> n;
    for (int i = 1; i < n; ++i) {
      int p; 
      in >> p;
      T[p - 1].push_back(i);
    }

    sz.resize(n);
    dfs(0);
    
    int flag = 1;
    for (int i = 0; i < n && flag; ++i) {
      if (T[i].size() >= 1) {
        int cont = 0;
        for (int v : T[i]) {
          cont += (sz[v] == 1);
        }
        if (cont >= 3) {
          ;
        } else {
          flag = 0;
          break;
        }
      }
    }

    out << (flag ? "Yes" : "No");
  } 

} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work(cin, cout);
}

