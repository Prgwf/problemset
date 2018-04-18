#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int N = 100000 + 7;


int main() {
  int n, A, B, C, T;
  cin >> n >> A >> B >> C >> T;

  int s = 0, x;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    s += T - x;
  }
  if (B < C) {
    cout << n * A + s * (C - B);
  } else {
    cout << n * A;
  }
}
