#include <bits/stdc++.h>
using namespace std;

int n, m;
int main() {
  while (scanf("%d %d", &n, &m) != EOF) {
    vector<int> f;
    for (int i = 1; i * i <= n; ++i) {
      if (n % i) continue;
      if (i * i == n) f.push_back(i);
      else {f.push_back(i); f.push_back(n / i);}
    }

    long long ans = 0;
    for (int x : f) {
      while (x) {
        int r = x % m;
        x /= m;
        ans += 1LL * r * r;
      }  
    }
    
    string out;
    while (ans) {
      int r = ans % m;
      ans /= m;
      if (r >= 10) out.push_back(char('A' + r - 10));
      else out.push_back(char('0' + r));  
    }
    reverse(out.begin(), out.end());
    printf("%s\n", out.c_str());
  }
}