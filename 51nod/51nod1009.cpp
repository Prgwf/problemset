/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const ll lnf = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 100000 + 20;

ll dp[12][12];
void work() {
  int n;
  cin >> n;
  int ans = 0;
  int base = 1;
  int h = n;
  while (n > 0) {
    int b = n % 10;
    if (b == 1) {
      ans += (n / 10) * base;
      ans += (h % base) + 1;
    } else if (!b) {
      ans += (n / 10) * base;
    } else {
      ans += (n / 10 + 1) * base;
    }
    base *= 10;
    n /= 10;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("data.in", "r", stdin);
  work();
}
