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
    ll L;
    in >> n >> L;
    vector<ll> c;
    c.resize(50);

    for (int i = 0; i < n; ++i) {
      in >> c[i];
    }
    
    for (int i = 1; i < n; ++i) {
      c[i] = min(c[i], c[i  -1] * 2);
    }

    for (int i = n - 2; i >= 0; --i) {
      c[i] = min(c[i], c[i + 1]);
    }

    for (int i = n; i < 31; ++i) {
      c[i] = c[i - 1] * 2;
    }

    ll ans = 0;
    for (int i = 0; i < 31; ++i) {
      if (ans > c[i]) {
        ans = c[i];
      }
      if ((L >> i) & 1) {
        ans += c[i];
      }
    }

    out << ans;
  } 

} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work(cin, cout);
}

