class Solution {
 public:
  int PARTITION_Method(vector<int>& numbers) {
    int n = numbers.size();
    int l = 0, r = n - 1;
    int mid = (l + r) / 2;

    int i = Partition(numbers, l, r);
    while (i != mid) {
      if (i > mid) {
        r = i - 1;
        i = Partition(numbers, l, r);
      } else {
        l = i + 1;
        i = Partition(numbers, l, r);
      }
    }

    int x = numbers[i];
    if (check(numbers, x)) {
      return x;
    }
    return 0;
  }

  int Partition(vector<int>& a, int l, int r) {
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

  int CNT_Method(const vector<int>& numbers) {
    int n = numbers.size();

    int cnt = 0, x;
    for (int i = 0; i < n; ++i) {
      if (cnt == 0) {
        x = numbers[i];
        cnt++;
      } else if (numbers[i] != x) {
        --cnt;
      } else {
        ++cnt;
      }
    }

    if (check(numbers, x)) {
      return x;
    }

    return 0;
  }

  bool check(const vector<int>& numbers, int x) {
    int n = numbers.size();

    int cnt = 0;
    for (const int& y : numbers) {
      if (x == y) {
        cnt++;
      }
    }

    return cnt * 2 > n;
  }

  int MoreThanHalfNum_Solution(const vector<int>& numbers) {
    int n = numbers.size();
    if (n <= 0) {
      return 0;
    }

    vector<int> a = numbers;
    return PARTITION_Method(a);
    // return CNT_Method(a);
  }
};