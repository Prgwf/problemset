/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

ll a[maxn], c[maxn];
void work() {
  int T;
  cin >> T;

  int kase = 0;
  while (T--) {
    int n, S;
    cin >> n >> S;

    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }

    int lb = 0, ub = n;
    int ans = 0, cost = 0;
    while (lb <= ub) {
      ll left = S;
      int mid = (lb + ub) / 2;

      for (int i = 1; i <= n; ++i) {
        c[i] = 1LL * a[i] + 1LL * i * mid;
      }
      sort(c + 1, c + 1 + n);
      for (int i = 1; i <= mid; ++i) {
        left -= c[i];
      }
      if (left >= 0) {
        ans = mid;
        cost = S - left;
        lb = mid + 1;
      } else {
        ub = mid - 1;
      }
    }

    cout << "Case #" << ++kase << ": "<< ans << " " << cost << "\n";
  }
  cout.flush();
}
int main() {
  // freopen("1.in", "r", stdin);
  // freopen("my.out", "w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
