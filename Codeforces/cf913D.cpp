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
  struct info {
    int id, need, cost;

    bool operator < (const info & rhs) const {
      return cost < rhs.cost;
    }
  } ;
  int n, T;
  vector<info> problem;

  bool check(int x) {
    int left = T, ret = 0;
    for (int i = 0; i < n; ++i) {
      if (problem[i].need >= x && left >= problem[i].cost) {
        ++ret;
        left -= problem[i].cost;
      }   
      if (ret >= x) break;
    }

    return ret >= x;
  }

  void work(istream &in, ostream &out) {
    in >> n >> T;
    problem.resize(n);

    for (int i = 0; i < n; ++i) {
      int a, t;
      in >> a >> t;
      problem[i] = {i, a, t};
    }
    sort(problem.begin(), problem.end());

    int ans = 0, lb = 0, ub = n;
    while (lb <= ub) {
      int mid = (lb + ub) / 2;
      if (check(mid)) {
        ans = mid;
        lb = mid + 1;
      } else {
        ub = mid - 1;
      }
    }

    vector<int> output;
    int left = T, ret = 0, x = ans;
    for (int i = 0; i < n; ++i) {
      if (problem[i].need >= x && left >= problem[i].cost) {
        ++ret;
        left -= problem[i].cost;
        output.push_back(problem[i].id + 1);
      }   
      if (ret >= x) break;
    }

    out << ans << "\n" << ans << "\n";
    for (int i : output) {
      out << i << " ";
    }
    out.flush();

  } 
} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work(cin, cout);
}

