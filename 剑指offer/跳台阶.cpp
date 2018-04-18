const int max =
class Solution {
public:
  int jumpFloor(int number) {
    vector<int> f(number + 1);
    f[0] = 0;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= number; ++i) {
      f[i] = f[i - 1] + f[i - 2];
    }
    return f[number];
  }
};
