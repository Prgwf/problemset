/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int moder = 1e9 + 7;


int main() {
  int n;
  scanf("%d", &n);
  vector<int> perm;

  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    perm.push_back(x);
  }

  vector<int> S;
  vector<int> ans;
  int now = n;
  for (int x : perm) {
    while (!S.empty() && S.back() == now) {
      now--;
      ans.push_back(S.back());
      S.pop_back();
    }

    S.push_back(x);
  } 
  while (!S.empty()) {
    ans.push_back(S.back());
    S.pop_back();
  }

  for (int i = 0; i < n; ++i) {
    printf("%d%c", ans[i], i < n - 1 ? ' ' : '\n');
  }
}
