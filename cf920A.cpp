#include <bits/stdc++.h>
using namespace std;

const int N = 205;
int t, n, k;
int pos[N];
bool water[N];
int main() {
  scanf("%d", &t);

  while (t--) {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; ++i) {
      scanf("%d", pos + i);
    }
    
    for (int i = 1; i <= n; ++i) water[i] = 0;
    
    int sec = 0, flag = 0;
    do {
      flag = 1;
      sec++;
      for (int i = 0; i < k; ++i) {
        int u = max(1, pos[i] - (sec - 1));
        int v = min(n, pos[i] + (sec - 1));
        water[u] = 1; water[v] = 1;
      }

      for (int i = 1; i <= n; ++i) {
        if (!water[i]) {
          flag = 0; break;
        }
      }

      if (flag) break;
    } while (true);

    printf("%d\n", sec);
  }

  return 0;
}