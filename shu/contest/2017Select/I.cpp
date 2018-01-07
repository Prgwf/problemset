/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

bool check(ll a, ll b, ll c) {
  return a * a + b * b == c * c;
}
void work() {
  int T;
  cin >> T;

  int kase = 0;
  string out[2] = {"No\n", "Yes\n"};
  while (T--) {
    long long a, b, c;
    cin >> a >> b >> c;
    int flag = 0;
    if (check(a, b, c) || check(a, c, b) || check(b, c, a)) {
      flag = 1;
    }
    cout << "Case #" << ++kase << ": " << out[flag];
  }
  cout.flush();
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
