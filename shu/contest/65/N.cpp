/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 26 * 26 * 26 * 26 + 3;
const int moder = 1e9 + 7;

struct Solution {
  int vis[26][26][26][26];
  int s[1000000] = {0, 0, 0};
  void work() {
    int T;
    scanf("%d", &T);
    
    memset(vis, 0, sizeof(vis));
    for (int i = 3; i < maxn; ++i) {
      for (int j = 25; j >= 0; --j) {
        if (vis[s[i - 3]][s[i - 2]][s[i - 1]][j]) continue;
        s[i] = j;
        vis[s[i - 3]][s[i - 2]][s[i - 1]][j] = 1;
        break;
      }
    }    

    string ans;
    for (int i = 0; i < maxn; ++i) {
      ans.push_back('a' + s[i]);
    }

    int kase = 0;
    while (T--) {
      int n;
      scanf("%d", &n);

      if (n > 26 * 26 * 26 * 26 + 3) {
        printf("Case #%d: %s\n", ++kase, "Impossible");
        continue;
      }
      
      printf("Case #%d: %s\n", ++kase, (ans.substr(0, n)).c_str());
    }
  } 

} ; 
Solution Woo;
int main() {
  Woo.work();
}

