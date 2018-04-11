#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 7;

int main() {
  int k, p;
  scanf("%d %d", &k, &p);
  int ret = 0;
  for (int i = 1; i <= k; ++i) {
    string i_ = to_string(i);
    string i_rev(i_.rbegin(), i_.rend());
    ret = (1LL * ret + stoll(i_ + i_rev)) % p;
  }
  printf("%d\n", ret % p);
}
