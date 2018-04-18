class Solution {
public:
  void sortColors(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    for (int i = 0 ;i < nums.size(); ++i) {
      if (i > r or i < l) break;
      if (nums[i] == 0) {
        swap(nums[l++], nums[i]);
      } else if (nums[i] == 2) {
        swap(nums[r--], nums[i]);
        --i;
      }
    }
  }
};
