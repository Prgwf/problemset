class Solution {
public:
    int Add(int num1, int num2)
    {
      int sum, c;
      do {
        sum = num1 ^ num2;
        c = (num1 & num2) << 1;
        num1 = sum;
        num2 = c;
      } while (num2 != 0);
      return sum;
    }
};
