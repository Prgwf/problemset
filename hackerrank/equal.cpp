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
    int T;
    in >> T;

    while (T--) {
      int n;
      in >> n;
      vector<int> a;
      a.resize(n);

      for (int i = 0; i < n; ++i) {
        in >> a[i];
      }

      int Min = *min_element(a.begin(), a.end());
      int ans = inf;
      for (int i = 0; i <= 5; ++i) {
        int temp = 0;
        for (int j = 0; j < n; ++j) {
          int k = (a[j] - (Min - i));
          temp += k / 5;
          k %= 5;
          temp += k / 2;
          temp += k & 1;
        }
        ans = min(ans, temp);
      }
      out << ans << endl;
    }
  } 

} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work(cin, cout);
}

