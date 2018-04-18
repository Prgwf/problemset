/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100 + 20;

char s[maxn];
int num1[maxn];
void work() {
  int T;
  scanf("%d", &T);

  int kase = 0;
  while (T--) {
    scanf("%s", s + 1);
    int n = strlen(s + 1);

    vector<int> A;
    memset(num1, 0, sizeof(num1));
    for (int i = 1; i <= n; ++i) {
      num1[i] = num1[i - 1];
      if (s[i] == 'Q') {
        num1[i] +=  1;
      } else if (s[i] == 'A') {
        A.push_back(i);
      }
    }

    int ans = 0;
    for (int i : A) {
      ans += num1[i - 1] * (num1[n] - num1[i]);
    }
    cout << "Case #" << ++kase << ": " << ans << "\n";
  }
  cout.flush();
}
int main() {
  // freopen("data.in", "r", stdin);
  // ios_base::sync_with_stdio(0);
  // cin.tie(0); cout.tie(0);

  work();
}
