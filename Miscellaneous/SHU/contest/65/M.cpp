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
  int ret[30][30][30][30];
  int dx[3] = {3, 0, 1};
  int dy[3] = {0, 3, 1};

  void dfs(int depth, int a, int b, int c, int d) {
    if (depth == 6) {
      ret[a][b][c][d]++;
      return;
    }
    
    for (int i = 0; depth == 0 && i < 3; ++i) {
      dfs(depth + 1, a + dx[i], b + dy[i], c, d);
    }

    for (int i = 0; depth == 1 && i < 3; ++i) {
      dfs(depth + 1, a + dx[i], b, c + dy[i], d);
    }

    for (int i = 0; depth == 2 && i < 3; ++i) {
      dfs(depth + 1, a + dx[i], b, c, d + dy[i]);
    }

    for (int i = 0; depth == 3 && i < 3; ++i) {
      dfs(depth + 1, a, b + dx[i], c + dy[i], d);
    }

    for (int i = 0; depth == 4 && i < 3; ++i) {
      dfs(depth + 1, a, b + dx[i], c, d + dy[i]);
    }

    for (int i = 0; depth == 5 && i < 3; ++i) {
      dfs(depth + 1, a, b, c + dx[i], d + dy[i]);
    }

  }
  void work(istream &in, ostream &out) {
    int T;
    in >> T;

    memset(ret, 0, sizeof(ret));
    dfs(0, 0, 0, 0, 0);

    int kase = 0;
    while (T--) {
      int a, b, c, d;
      in >> a >> b >> c >> d;

      out << "Case #" << ++kase << ": ";
      if (ret[a][b][c][d] == 0) {
        out << "Wrong Scoreboard\n";
      } else if (ret[a][b][c][d] == 1) {
        out << "Yes\n";
      } else {
        out << "No\n";
      }
    }
  } 

} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work(cin, cout);
}

