/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 20;
const int moder = 1e9 + 7;

struct Solution {
  int n, m, wager, increase, damage;
  tuple<int, int, int> health_points[maxn * 2];
  map<int, int> cont;
  set<int> updates[maxn];
  int used[maxn];
  int max_health[maxn];
  int base_health[maxn];
  int regen[maxn];

  void work(istream &in, ostream &out) {
    in >> n >> m >> wager >> increase >> damage;

    for (int i = 0; i < n; ++i) {
      in >> max_health[i] >> base_health[i] >> regen[i];
      if (max_health[i] <= damage && increase > 0) {
        out << -1;
        return;
      }
      health_points[i] = make_tuple(0, i, base_health[i]);
    }

    for (int i = 0; i < m; ++i) {
      int t, j, h;
      in >> t >> j >> h;
      --j;
      health_points[n + i] = make_tuple(t, j, h);
      updates[j].insert(t);
    }

    sort(health_points, health_points + n + m);

    for (int i = 0; i < m + n; ++i) {
      int t, j, h;
      tie(t, j, h) = health_points[i];

      if (h <= damage) {

        if (!used[j]) {
          cont[t]++;
          used[j] = true;
        } else {
          if (regen[j] > 0) {
            ll at = t + (damage - h) / regen[j] + 1;
            if (max_health[j] > damage 
                && updates[j].upper_bound(t) == updates[j].upper_bound(at)) {
              cont[at]--;
              cont[at - 1] += 0;
              used[j] = false;
            }
          } else {
            if (updates[j].upper_bound(t) == updates[j].end() 
                && increase > 0) {
              out << -1;
              return;
            }
          }
        }
      } else {
        if (used[j]) {
          cont[t]--;
          cont[t - 1] += 0;
          used[j] = false;
        }
      }
    }

    ll ans = 0;
    int tot = 0;

    for (auto p : cont) {
      ll at, val;
      tie(at, val) = p;

      tot += val;

      ans = max(ans, 1LL * tot * wager + 1LL * at * tot * increase);
    }

    out << ans << endl;
  }
} ; 

Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work(cin, cout);
}

