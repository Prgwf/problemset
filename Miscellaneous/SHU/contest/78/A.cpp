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
    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      sum += x;
    }
    cout << sum / n << endl;
  }

} ; 
Solution Woo;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  Woo.work();
}

