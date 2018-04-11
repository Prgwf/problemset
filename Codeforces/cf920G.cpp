#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 20;

vector<int> a[N];
vector<int> Q;
int t, x, p, k;

int solve(int n, int p) {
  int ret = 0;
  Q.clear();
  Q.push_back(-1);
  vector<int> & f = a[p];
  for (int i = 0; i < (int)f.size(); ++i) {
    int top = Q.size();
    for (int j = 0; j < top; ++j) {
      Q.push_back(-1 * f[i] * Q[j]);
    }
  }
  for (int i = 1; i < (int)Q.size(); ++i) {
    ret += n / Q[i];  
  }
  return n - ret;
}

int main() {
  for (int i = 2; i <= 1000000; ++i) {
    if (a[i].size() > 0) continue;
    for (int j = i; j <= 1000000; j += i) {
      a[j].push_back(i);
    }
  }

  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &x, &p, &k);

    k += solve(x, p);
    int lb = 1, ub = 1e9, ans = x;
    while (lb <= ub) {
      int mid = (lb + ub) / 2;
      if (solve(mid, p) >= k) {
        ans = mid;
        ub = mid - 1;
      } else {
        lb = mid + 1;
      }
    }
    printf("%d\n", ans);
  }  
}