#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll sum = 0;
  for (int i = 1; i <= 100; ++i) {
    for (int j = i + 1; j <= 100; ++j) {
      sum += 2LL * i * j;
    }
  }
  printf("%lld\n", sum);
}