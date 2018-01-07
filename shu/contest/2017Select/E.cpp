/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;

void work() {
  int T;
  cin >> T;

  int kase = 0;
  while (T--) {
    int n;
    cin >> n;

    vector<int> a;
    a.resize(n);

    int flag1 = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      flag1 += (a[i] <= 2);
    }
    flag1 = (flag1 == 2);

    sort(a.begin(), a.end());
    a.pop_back();
    --n;
    int flag2 = 1;
    for (int i = 1; i < n; ++i) {
      if (a[i] - a[i - 1] > 2) {
        flag2 = 0;
      }
    }

    string ans[2] = {"Bad Problem Set\n", "Good Problem Set\n"};
    cout << "Case #" << ++kase << ": "<< ans[flag1 && flag2];
  }
  cout.flush();
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
