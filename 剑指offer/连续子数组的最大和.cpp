class Solution {
 public:
  int FindGreatestSumOfSubArray(vector<int> array) {
    int n = array.size();

    if (n <= 0) {
      return 0;
    }

    int sum = 0, ans = -0x3f3f3f3f;
    for (int i = 0; i < n; ++i) {
      if (sum > 0) {
        sum += array[i];
      } else {
        sum = array[i];
      }

      if (sum > ans) {
        ans = sum;
      }
    }
    return ans;
  }  
};