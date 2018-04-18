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
    ll A, B;
    in >> A >> B;

    ll x, y, z;
    in >> x >> y >> z;

    ll needA = x * 2LL + y;
    ll needB = z * 3LL + y;

    ll ansA = max(0LL, needA - A);
    ll ansB = max(0LL, needB - B);

    out << ansA + ansB << endl;
  } 

} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work(cin, cout);
}

