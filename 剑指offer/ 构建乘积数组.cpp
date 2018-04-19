class Solution {
 public:
  vector<int> multiply(const vector<int>& A) {
    int n = A.size();
    if (n < 0) {
      return {};
    }
    
    vector<int> B(n);
    B[0] = 1;

    for (int i = 1; i < n; ++i) {
      B[i] = B[i - 1] * A[i - 1];
    }

    int rig = 1;
    for (int i = n - 2; i >= 0; --i) {
      rig *= A[i + 1];
      B[i] *= rig;
    }
    return B;
  }
};