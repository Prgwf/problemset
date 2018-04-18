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
    list<int> L;
    unordered_map<int, list<int>::iterator> mep;
    int cap, n, hit = 0;
    scanf("%d%d", &cap, &n);
    for (int i = 0; i < n; ++i) {
      int id;
      scanf("%d", &id);
      auto it = mep.find(id);
      if (it != mep.end()) {
        hit++;
        L.splice(L.begin(), L, it->second);
        continue;
      }
      L.push_front(id);
      mep[id] = L.begin();
      if ((int)L.size() > cap) {
        mep.erase(L.back());
        L.pop_back();
      }
    }
    printf("%d\n", hit);
  }
}
