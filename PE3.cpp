#include <bits/stdc++.h>
using namespace std;

int main() {
  long long num = 600851475143;
  int n = sqrt(num);
  for (int i = 2; i <= n; ++i) {
    if (num % i) continue;
    while (num % i == 0) num /= i;
    printf("%d\n", i);  
  }
  if (num != 1) printf("%lld\n", num);
}