#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool Find(int target, vector<vector<int> > array) {
    int rsiz = array.size();
    int csiz = array[0].size();
    if (rsiz && csiz) {
      int r = 0, c = csiz - 1;
      while (r < rsiz && c >= 0) {
        if (array[r][c] == target) {
          return true;
        } else if (array[r][c] > target) {
          --c;
        } else {
          ++r;
        }
      }
    }
    return false;
  }
};

int main() {
  Solution().Find(5, {{1, 2}, {3, 5}});
}
