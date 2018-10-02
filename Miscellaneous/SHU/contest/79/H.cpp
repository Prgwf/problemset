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

  void work() {
    int T;
    scanf("%d", &T);

    while (T--) {
      int n, q;
      scanf("%d%d", &n, &q);

      multiset<pair<int, int>> Set;
      for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        Set.insert({x, y});
      }

      int ans = 0;
      for (int i = 0; i < q; ++i) {
        int x, y, r;  
        scanf("%d%d%d", &x, &y, &r);

        auto lb = Set.lower_bound({x - r, inf});
        auto ub = Set.lower_bound({x + r, -inf});

        vector<multiset<pair<int, int>>::iterator> del;
        for (auto it = lb; it != ub; ++it) {
          int x1 = it->first;
          int y1 = it->second;
          if ((x - x1) * (x - x1) + (y - y1) * (y - y1) < r * r) {
            ans++;
            del.push_back(it);
          }
        }

        for (auto it : del) {
          Set.erase(it);
        }

      }

      printf("%d\n", ans);
      puts("");
    }
  }

} ; 
Solution Woo;
int main() {
  Woo.work();
}

