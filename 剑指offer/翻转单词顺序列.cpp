class Solution {
 public:
  string ReverseSentence(string str) {
    int n = str.size();

    reverse(str.begin(), str.end());

    int l = 0;
    for (int r = 0; r < n; ++r) {
      if (str[r] == ' ') {
        reverse(str.begin() + l, str.begin() + r);
        l = r + 1;
      }
      if (r == n - 1) {
        reverse(str.begin() + l, str.end());
      }
    }
    return str;
  }
};