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

      ll sum = 0;
      if (n <= 0) {
        for (int i = n; i <= 1; ++i) {
          sum += 1LL * i;
        }
      } else {
        for (int i = 1; i <= n; ++i) {
          sum += 1LL * i;
        }
      }
      out << sum << endl;
    }
  } 

} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work(cin, cout);
}

