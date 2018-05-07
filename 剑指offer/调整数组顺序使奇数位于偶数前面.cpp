class Solution {
public:
  void reOrderArray(vector<int> & array) {
    if (array.size() == 0) return;

    vector<int> t;
    for (int & x : array) {
      if (x & 1) {
        t.emplace_back(x);
      }
    }
    for (int & x : array) {
      if (!(x & 1)) {
        t.emplace_back(x);
      }
    }
    swap(t, array);
  }
  void reOrderArraywa(vector<int> & array) {
    if (array.size() == 0) return;

    int l = 0, r = array.size();
    while (l < r) {
      while (l < r && array[l] & 1) l++;
      while (l < r && !(array[r] & 1)) r--;

      swap(array[l], array[r]);
    }
  }
};
