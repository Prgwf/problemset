/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int a[125][6];
int num[6], tnum[6];
int get_value(int t, int ac, int all) {
  if (t < 0) {
    return 0;
  }

  int limit;
  if (2 * ac > all) {
    limit = 500;
  } else if (4 * ac > all) {
    limit = 1000;
  } else if (8 * ac > all) {
    limit = 1500;
  } else if (16 * ac > all) {
    limit = 2000;
  } else if (32 * ac > all) {
    limit = 2500;
  } else {
    limit = 3000;
  }

  return limit - limit / 250 * t;
}
void work() {
  int T;
  cin >> T;

  int kase = 0;
  while (T--) {
    int n;
    cin >> n;

    memset(num, 0, sizeof(num));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= 5; ++j) {
        cin >> a[i][j];
        if (a[i][j] >= 0) {
          ++num[j];
        }
      }
    }

    int ans = -1;
    for (int i = 0; i <= n * 32; ++i) {
      for (int j = 1; j <= 5; ++j) {
        tnum[j] = num[j];
      }

      for (int j = 1; j <= 5; ++j) {
        if (a[1][j] < 0 || a[2][j] < 0) continue;
        if (a[1][j] > a[2][j]) {
          tnum[j] += i;
        }
      }

      int x = 0, y = 0;
      for (int j = 1; j <= 5; ++j) {
        x += get_value(a[1][j], tnum[j], n + i);
        y += get_value(a[2][j], tnum[j], n + i);
      }

      if (x > y) {
        ans = i;
        break;
      }
    }

    cout << "Case #" << ++kase << ": " << ans << "\n";
  }
  cout.flush();
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
#endif

  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
