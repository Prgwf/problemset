class Solution {
 public:
  int GetNumberOfK(vector<int> data, int k) {
    int n = data.size();

    int l = LowerBound(data, k);
    if (l < 0) {
      return 0;
    }
    
    int r = UpperBound(data, k);
    if (r < 0) {
      return n - l;
    } else {
      return r - l;
    }
  }
  
  int LowerBound(const vector<int> & v, int x) {
    int ans = -1;
    int lb = 0, ub = v.size() - 1;
    while (lb <= ub) {
      int mid = (lb + ub) / 2;
      if (v[mid] >= x) {
        ans = mid;
        ub = mid - 1;
      } else {
        lb = mid + 1;
      }
    }
    return ans;
  }

  int UpperBound(const vector<int> & v, int x) {
    int ans = -1;
    int lb = 0, ub = v.size() - 1;
    while (lb <= ub) {
      int mid = (lb + ub) / 2;
      if (v[mid] > x) {
        ans = mid;
        ub = mid - 1;
      } else {
        lb = mid + 1;
      }
    }
    return ans;
  }
};