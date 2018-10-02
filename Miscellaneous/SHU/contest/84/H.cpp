/*
教练我想打ACM~
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 7;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    deque<int> Q;
    int cap, n, hit = 0;
    scanf("%d%d", &cap, &n);
    for (int i = 0; i < n; ++i) {
      int id;
      scanf("%d", &id);
      int inq = 0;
      for (int i : Q) {
        if (i == id) {
          inq = 1;
          ++hit;
          break;
        }
      }
      if (!inq) {
        if ((int)Q.size() < cap) {
          Q.push_back(id);
        } else {
          Q.pop_front();
          Q.push_back(id);
        }
      }
    }
    printf("%d\n", hit);
  }
}
