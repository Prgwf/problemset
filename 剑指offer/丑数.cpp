class Solution {
 public:
  Solution() {
    factor = {2, 3, 5};
    dfs(0, 1LL);
    sort(Numbers.begin(), Numbers.end());
  }

  void dfs(int i, long long x) {
    if (i == 3) {
      Numbers.push_back(x);
      return;
    }

    dfs(i + 1, x);
    while (x * factor[i] > 0 && x * factor[i] < 2e9) {
      dfs(i + 1, x *= factor[i]);
    }
  }

  int GetUglyNumber_Solution(int index) {
    if (index == 0) return 0;

    return Numbers[index - 1];
  }

 private:
  vector<long long> factor;
  vector<long long> Numbers;
};
