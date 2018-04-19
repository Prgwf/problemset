class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
      int sum = 0;
      for (int x : data) {
        sum ^= x;
      }
      int i = 0;
      for (; i < 31; ++i) {
        if (sum >> i & 1) {
          break;
        }
      }
      *num1 = 0;
      *num2 = 0;
      for (int x : data) {
        if (x >> i & 1) {
          *num1 ^= x;
        } else {
          *num2 ^= x;
        }
      }
    
    }
};