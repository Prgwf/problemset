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
    ll n, k;
    in >> n >> k;

    if (k == 1) {
      out << n;
      return;
    }

    int i = 0;
    for (i = 63; i >= 0; --i) {
      if (n >> i & 1) {
        break;
      }
    } 
    ll ans = (1LL << (i + 1)) - 1LL;
    out << ans;
  } 

} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work(cin, cout);
}

