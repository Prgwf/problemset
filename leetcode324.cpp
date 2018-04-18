class Solution {
public:
  void wiggleSort(vector<int>& nums) {
    int n = nums.size();
    auto midptr = nums.begin() + n / 2;
    nth_element(nums.begin(), midptr, nums.end());
    int mid = *midptr;

    #define A(i) nums[(2*(i) + 1) %(n|1)]

    int l = 0, r = n - 1;
    for (int i = 0; i < n && i <= r; ++i) {
      if (A(i) > mid) {
        swap(A(i), A(l));
        l++;
      } else if (A(i) < mid) {
        swap(A(i), A(r));
        r--; i--;
      }
    }
  }
};
