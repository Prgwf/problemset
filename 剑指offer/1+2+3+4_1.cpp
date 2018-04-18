class Solution {
public:
    Solution() {
      ++n_;
      sum_ += n_;
    }
    void Resert() {
      n_ = 0;
      sum_ = 0;
    }

    unsigned int GetSum() {
      return sum_;
    }

    unsigned int Sum_Solution(int);

private:
  static unsigned int n_;
  static unsigned int sum_;
};

unsigned int Solution::n_ = 0;
unsigned int Solution::sum_ = 0;

unsigned int Solution::Sum_Solution(int n) {
  Resert();
  Solution *p = new Solution[n];
  delete []p;
  p = nullptr;

  return GetSum();
}
