/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int pri[3];
int solve(vector<int>& v) {
  int mx = -1;
  for (int i = 0; i < 3; ++i) {
    if (mx == -1 || (v[i] > v[mx]) || (v[i] == v[mx] && pri[i] > pri[mx])) {
      mx = i;
    }
  }
  return mx;
}

int main() {
  for (int i = 0; i < 3; ++i) {
    scanf("%d", pri + i);
  }

  vector<int> info{0, 0, 0};
  for (int i = 0; i < 100; ++i) {
    int y = solve(info);
    int x = (y - 1 + 3) % 3;
    printf("%d\n", x + 1);
    info[x]++;
  }
}
