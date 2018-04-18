/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 20;


ll num[2001];
void work() {
  int T;
  cin >> T;

  int kase = 0;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a;
    a.resize(n);

    memset(num, 0, sizeof(num));
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      num[a[i] + 500]++;
    }

    ll ans = 0;

    // ai + aj = ak  (i != j != k)
    for (int i = 0; i <= 1000; ++i) {
      for (int j = 0; j <= 1000; ++j) {
        int k = (i - 500) + (j - 500) + 500;
        if (i - 500 == 0 || j - 500 == 0) continue;
        if (i == j) continue;
        if (k < 0 || k > 1000) continue;

        ans += 1LL * num[i] * num[j] * num[k];
      }
    }

    /*
    0 + 0 = 0 (i != j != k)
    0 + aj = ak (j != k)
    */
    if (num[500] > 0) {
      if (num[500] >= 3) { // P(k, 3);
        ans += 1LL * num[500] * (num[500] - 1LL) * (num[500] - 2LL);
      }

      for (int i = 0; i <= 1000; ++i) {
        if (i - 500 != 0 && num[i]) {
          ans += 2LL * (num[i] - 1) * num[i] * num[500];
        }
      }
    }

    // ai + aj = ak (ai == aj, i != j)
    for (int i = 0; i <= 1000; ++i) {
      int _2i = i - 500 + i - 500 + 500;
      if (i == 500 || _2i < 0 || _2i > 1000) continue;
      ans += 1LL * (num[i] - 1) * num[i] * num[i - 500 + i - 500 + 500];
    }

    cout << "Case #" << ++kase << ": " << ans << "\n";
  }
  cout.flush();
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
