class Solution {
 public:
  vector<int> GetLeastNumbers_Solution(vector<int> & a, int k) {
    int n = a.size();

    if (k <= 0 or k > n) {
      return {};
    }


    int l = 0, r = n - 1;
    int i = Partition(a, l, r);

    while (i != k - 1) {
      if (i > k - 1) {
        r = i - 1;
        i = Partition(a, l, r);
      } else {
        l = i + 1;
        i = Partition(a, l, r);
      }
    }

    sort(a.begin(), a.begin() + k);
    return {a.begin(), a.begin() + k};
  }


  int Partition(vector<int> & a, int l, int r) {
    int pivot = a[l];

    while (l < r) {
      while (l < r && a[r] >= pivot) {
        r--;
      }

      if (l < r) {
        swap(a[l], a[r]);
        l++;
      }


      while (l < r && a[l] <= pivot) {
        l++;
      }

      if (l < r) {
        swap(a[l], a[r]);
        r--;
      }
    }

    a[l] = pivot;
    return l;
  }
};