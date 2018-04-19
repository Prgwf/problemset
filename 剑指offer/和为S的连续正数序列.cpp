class Solution {
 public:
  vector<vector<int> > FindContinuousSequence(int sum) {
    vector<vector<int> > ans;

    int l = 1, r = 2;
    int mid = (sum + 1) / 2;
    int cur = l + r;
    while (l < mid) {
      if (cur == sum) {
        ans.emplace_back(GetArray(l, r));
      }

      if (cur > sum && l < mid) {
        cur -= l;
        l++;
        continue;
      }

      r++;
      cur += r;
    }
    return ans;
  }

  vector<int> GetArray(int l, int r) {
    vector<int> ret;
    for (int i = l; i <= r; ++i) {
      ret.emplace_back(i);
    }
    return ret;
  }
} ;