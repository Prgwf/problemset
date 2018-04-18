/*
教练我想打ACM～
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int maxn = 3500000 + 20;
const int moder = 1e9 + 7;

struct Solution {
  int prime[maxn] = {0};
  int num_prime;
  int not_prime[maxn] = {1, 1};
  void get_prime() {
    for (int i = 2; i < maxn; ++i) {
      if (!not_prime[i]) prime[++num_prime] = i;
      for (int j = 1; j <= num_prime && i * prime[j] < maxn; ++j) {
        not_prime[i * prime[j]] = 1;
        if (i % prime[j] == 0) break;
      }
    }
  }

  int S[maxn];
  void work() {
    get_prime();
    S[0] = 0;
    S[1] = 0;
    for (int i = 2; i <= 1000000; ++i) {
      S[i] = S[i - 1] + (!not_prime[3 * i + 7]);
    }
    int T;
    scanf("%d", &T);
    int kase = 0;
    while (T--) {
      int n;
      scanf("%d", &n);
      printf("Case #%d: %d\n", ++kase, S[n]);
      // out << "Case #" << ++kase << ": " << S[n] << "\n";
    }
  } 

} ; 
Solution Woo;
int main() {
  // ios_base::sync_with_stdio(0);
  // cin.tie(0); cout.tie(0);
  Woo.work();
}

