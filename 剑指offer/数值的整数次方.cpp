const double eps = 1e-7;
class Solution {
public:
  double Power(double base, int exponent) {
    double ret = 1.0;
    if (exponent < 0 && abs(base) < eps) {
      return 0.0;
    }
    int e = abs(exponent);
    while (e) {
      if (e & 1) {
        ret = ret * base;
      }
      base = base * base;
      e >>= 1;
    }
    if (exponent < 0) {
      ret = 1.0 / ret;
    }
    return ret;
  }
};
