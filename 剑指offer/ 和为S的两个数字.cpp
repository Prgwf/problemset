class Solution {
 public:
  vector<int> FindNumbersWithSum(vector<int> array, int sum) {
    int l = 0, r = array.size() - 1;
    if (r <= 0) {
      return {};
    }
    while (l < r) {
      int x = array[l] + array[r];
      if (x < sum) {
        ++l;
      } else if (x > sum) {
        --r;
      } else {
        return {array[l], array[r]};
      }
    }
    return {};
  }
};