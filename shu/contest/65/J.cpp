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
  while (T--) {
    int n;
    cin >> n;
    int unuse;
    for (int i = 0; i < 2 * n; ++i) {
      cin >> unuse;
    }
    cout << "Case #" << ++kase << ": CSL\n";
  }
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
