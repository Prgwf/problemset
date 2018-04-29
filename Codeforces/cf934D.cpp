#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int N = 2333;

i64 p, k;
i64 a[N];

i64 foo() {
  i64 x = p % k;
  if (x < 0) x += k;
  return x % k;
}

int main() {
  scanf("%lld %lld", &p, &k);

  int i = 0;
  while (p) {
    i64 x = foo();
    a[i++] = x;
    p -= x;
    p /= (-k);
  }

  printf("%d\n", i);
  for (int j = 0; j < i; ++j) printf("%lld ", a[j]);
  printf("\n");
}