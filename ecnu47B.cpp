/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 20000 + 20;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  char mx = *max_element(s.begin(), s.end());
  int n = (int)s.size();

  vector<int> pos;
  for (int i = 0; i < n; ++i) {
    if (s[i] == mx) {
      pos.push_back(i);
    }
  }
  string ans;
  for (int i : pos) {
    ans = max(ans, s.substr(i));
  }
  int last = ans.size();
  for (int i = ans.size() - 1; ~i; --i) {
    if (ans[i] == '0') {
      last = i;
    } else {
      break;
    }
  }
  if (!last) {
    cout << 0;
  } else {
    cout << ans.substr(0, last);
  }
}
