#include <bits/stdc++.h>
using namespace std;

int fib[100];
int vis[1020000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  fib[1] = fib[2] = 1;
  vis[1] = 1;
  for (int i = 3; i <= 25; ++i) {
    fib[i] = fib[i - 1] + fib[i - 2];
    vis[fib[i]] = 1;
    if (fib[i] > 1000) break;
  }

  int n;
  cin >> n;
  string ans(n, ' ');
  for (int i = 0; i < n; ++i) {
    if (vis[i + 1]) ans[i] = 'O';
    else ans[i] = 'o';
  }
  cout << ans << endl;
}