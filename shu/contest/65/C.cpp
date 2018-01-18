/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 20;

ll L[maxn];
void work() {
  int T;
  cin >> T;

  int kase = 0;
  while (T--) {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
      cin >> L[i];
    }

    if (m > n) {
      cout << "Case #" << ++kase << ": "<< 0 << "\n";
      continue;
    }

    ll light = 0;
    for (int i = 1; i < m; ++i) {
      light += L[i];
    }

    int l = 1, r = m;
    int ans = 0;
    while (r <= n) {
      light += L[r];
      ans += int(light >= k);
      light -= L[l];
      r++; l++;
    }
    cout << "Case #" << ++kase << ": "<< ans << "\n";
  }
  cout.flush();
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
