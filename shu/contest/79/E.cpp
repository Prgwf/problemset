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

  void work() {
    int T;
    cin >> T;

    while (T--) {
      int n, m;
      cin >> n >> m;

      if (m % n == 0) {
        cout << n << endl;
        continue;
      }
      cout << m % n << endl;
    }
  }

} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work();
}

