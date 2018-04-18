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
  int n, m, r, k;
  struct node {
    double value;
    pair<int, int> pii;

    bool operator < (const node & rhs) const {
      return value < rhs.value;
    }
  } ;
  node get_info(const pair<int, int> &pii) {
    int x = pii.first;
    int y = pii.second;


    int lbx = max(1, x - r + 1);
    int ubx = min(x, n - r + 1);
    int lby = max(1, y - r + 1);
    int uby = min(y, m - r + 1);

    double value = 1.0 *  (ubx - lbx + 1) /(n - r + 1) * 1.0 * (uby - lby + 1) / (m - r + 1);
    return (node){value, pii};
  }

  bool inside(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m) return 0;

    return 1;
  }
  void work(istream &in, ostream &out) {
    in >> n >> m >> r >> k;
  
    map<pair<int, int>, bool> vis;
    pair<int, int> mid = {(n + 1) / 2, (m + 1) / 2};
    priority_queue<node> Q;
    Q.push(get_info(mid));
    vis[mid] = 1;

    double ans = 0;
    while (k--) {
      auto T = Q.top(); Q.pop();

      ans += T.value;

      int x = T.pii.first;
      int y = T.pii.second;


      for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
          if (dx == 0 && dy == 0) {
            continue;
          }
          int tx = x + dx;
          int ty = y + dy;
          pair<int, int> tp = {tx, ty};
          if (inside(tx, ty) 
              && !vis.count(tp)) {
            vis[tp] = 1;
            node tn = get_info(tp);
            Q.push(tn);
          }
        }
      }
    }
    out << setiosflags(ios::fixed);
    out << setprecision(12) << ans << endl;
  }

} ;
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work(cin, cout);
}

