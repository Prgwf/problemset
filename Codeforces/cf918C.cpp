#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  int n = s.size();
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int cnt = 0, lef = 0;
    for (int j = i; j < n; ++j) {
      if (s[j] == '(') {
        ++lef;
      } else if (s[j] == ')') {
        --lef;
      } else {
        if (lef == 0) {
          ++lef;
        } else {
          --lef;
          ++cnt;
        }
      }

      if (lef < 0) {
        if (cnt == 0) break;
        lef += 2;
        --cnt;
      }

      if (lef == 0) {
        ++ans;
      }
    }
  }

  printf("%d\n", ans);
}

