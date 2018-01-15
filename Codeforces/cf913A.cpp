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
    ll n, m;
    in >> n >> m;

    
    ll x = 1LL, i = 0;
    while (x <= m) {
      x *= 2LL;
      ++i;
    }

    if (i < n) {
      out << m;
      return;
    }
    out << m % (int)pow(2, n);
  } 

} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work(cin, cout);
}

