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

  string whatever;
  void work() {
    int n;
    cin >> n;
    
    double sum = 0;
    double tot = 0;
    for (int i = 0; i < n; ++i) {
      cin >> whatever;
      double x, y;
      cin >> x >> y;

      double point;
      if (y >= 90.0) {
        point = 4.0;
      } else if (y >= 85) {
        point = 3.7;
      } else if (y >= 82) {
        point = 3.3;
      } else if (y >= 78) {
        point = 3.0;
      } else if (y >= 75) {
        point = 2.7;
      } else if (y >= 72) {
        point = 2.3;
      } else if (y >= 68) {
        point = 2.0;
      } else if (y >= 66) {
        point = 1.7;
      } else if (y >= 64) {
        point = 1.5;
      } else if (y >= 60) {
        point = 1.0;
      } else {
        point = 0;
      }
      
      tot += x;
      sum += point * x;
    }

    cout.precision(4);
    cout << fixed << sum / tot << endl;
  }

} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work();
}

