#include <bits/stdc++.h>
using namespace std;


int main() {
  long long u = 1LL, v = 1LL;
  long long sum = 0, t = 0;
  for (; t <= 4000000; ) {
    t = u + v;
    if (t % 2 == 0) sum += t;
    v = u; u = t;   
  }
  cout << sum;
}