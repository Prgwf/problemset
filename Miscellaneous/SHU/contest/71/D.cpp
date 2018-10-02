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

  void work(istream &in, ostream &out) {
    int n;
    in >> n;
    vector<pair<int, int>> city;

    for (int i = 0; i < n; ++i) {
      int x, y;
      in >> x >> y;

      city.emplace_back(x, y);
      sort(city.begin(), city.end());
    }

    int ans = 0;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (city[j].second < city[i].second) {
          dp[i] = max(dp[i], dp[j] + 1);      
          ans = max(ans, dp[i]);
        }
      }
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

