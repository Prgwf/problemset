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
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};

  int n, m, r, k;
  pair<ll, pair<int, int>> calc(int x, int y) {
    
  }

  void work(istream &in, ostream &out) {
    in >> n >> m >> r >> k;

    pair<int, int> mid = {(n + 1) / 2, (m + 1) / 2};

    map<pair<int, int>, int> mep;
    mep.insert({mid, 1});
    priority_queue<pair<ll, pair<int, int>>> Q;

    double ans = 0;
    while (k--) {
      auto T = Q.top();
      Q.pop();
      ans += T.first * 1.0 / (n - r + 1) * 1.0 / (m -r + 1);
      int x = T.second.first;
      int y = T.second.second;
      for (int i = 0; i < 4; ++i) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        pair<int, int> tpii = {tx, ty};
        if (tx >= 1 && tx <= n && ty >= 1 && ty <= m) {
          if (mep.find(tpii) == mep.end()) {
            Q.push(calc(tx, ty));
            mep[tpii] = 1;
          }
        }
      }
    }
    
    out << setprecision(10) << ans << endl;
  } 

} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work(cin, cout);
}

