#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> a;

  for (int i = 0; i <n; ++i) {
    int x;
    scanf("%d", &x);
    a.push_back(x);
  }
  sort(a.begin(), a.end(), greater<int>());

  for (int x : a) {
    // printf("%d", x);
    if (k % x == 0) {
      printf("%d\n", k / x);
      return 0;
    }
  }
}

