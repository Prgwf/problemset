#include <bits/stdc++.h>
using namespace std;

int n, A, B;
int main() {
  vector<pair<int, int>> a, b;
  while (scanf("%d%d%d", &n, &A, &B) != EOF) {
    a.clear(); 
    b.clear(); 
    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      if (x < 0) x = 0;
      a.emplace_back(x, i);
    }

    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      if (x < 0) x = 0;
      b.emplace_back(x, i);
    }
    vector<pair<int, int>> tb = b;
    sort(a.begin() + 1, a.end(), greater<pair<int, int>>());

    vector<int> psum(n, 0);
    for (int i = 1; i <= n; ++i) {
      b[i] = tb[a[i].second];
      psum[i] += psum[i - 1] + a[i].first;
    }

    int ans = 0;
    int delta = 0;
    for (int i = 1; i <= n; ++i) {
      int sum = psum[i];
      for (int j = i + 1; j <= n; ++j) {
        if (b[j].second > i) {
          sum += b[j].first;
        }
      }
      
      if (b[i].first - a[i].first > 0) {
        delta += b[i].first - a[i].first;
      }
      sum += delta; 
      ans = max(ans, sum);
    }
    printf("%d\n", ans);
  }
}
