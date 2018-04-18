#include <bits/stdc++.h>
template <unsigned int n>
struct Sum {
  enum Value {
    N = Sum<n - 1>::N + n
  };
} ;
template <>
struct Sum<1> {
  enum Value{
    N = 1
  };
} ;

int main() {
  printf("%d\n", Sum<100>::N);
}
