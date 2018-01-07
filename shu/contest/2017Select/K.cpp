/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

void work() {
  int T;
  cin >> T;

  int kase = 0;
  const int moder = 1e9 + 7;
  while (T--) {
    int n;
    cin >> n;

    ll base = 2, ret = 1;
    while (n) {
      if (n & 1) {
        ret = ret * base % moder;
      }
      base = base * base % moder;
      n >>= 1;
    }

    cout << "Case #" << ++kase << ": " << ret - 1 << endl;
  }
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
