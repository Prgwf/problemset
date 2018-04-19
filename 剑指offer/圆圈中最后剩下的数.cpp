#include <bits/stdc++.h>
using namespace std;

class FunkList {

public:
  int n;
  vector<int> prev, next;

  void remove(int i) {
    next[prev[i]] = next[i];
    prev[next[i]] = prev[i];
  }

  FunkList(int _n) : n(_n) {
    prev.resize(n);
    next.resize(n);

    for (int i = 0; i < n; ++i) {
      prev[i] = i - 1;
      next[i] = i + 1;
    }
    prev[0] = n - 1;
    next[n - 1] = 0;
  }
} ;

class Solution {
 public:
  int LastRemaining_Solution(int n, int m) {
    if (n < 1 or m < 1) {
      return -1;
    }
    
    if (n == 1) {
      return 0;
    }

    FunkList numbers(n);
    int cnt = n;
    int pos = 0;
    while (cnt > 1) {
      for (int i = 1; i < m; ++i) {
        pos = numbers.next[pos];
      }
      
      --cnt;      
      int nxt = numbers.next[pos];
      numbers.remove(pos);
      pos = nxt;
    }

    return pos;
  }
};

int main(int argc, char const *argv[])
{
  int ret = Solution().LastRemaining_Solution(5, 3);
  printf("%d\n", ret);
  return 0;
}