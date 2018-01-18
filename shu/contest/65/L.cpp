/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int n;
int ans;
vector<int> word;
void dfs(int x, int state, int tot) {
  if (x == n) {
    ans = max(ans, tot);
    return;
  }

  dfs(x + 1, state, tot);
  if ((state & word[x]) == 0) {
    dfs(x + 1, state | word[x], tot + 1);
  }
}
void work() {
  int T;
  cin >> T;
  int kase = 0;
  while (T--) {
    cin >> n;
    word.clear();
    for (int i = 0; i < n; ++i) {
      string temp;
      cin >> temp;
      int state = 0;
      for (char & ch : temp) {
        state |= (1 << int(ch - 'a'));
      }
      word.push_back(state);
    }
    ans = 0;
    dfs(0, 0, 0);
    cout << "Case #" << ++kase << ": " << ans << endl;
  }
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
