#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:

  int InversePairs(vector<int> data) {
    if (data.size() <= 1) {
      return 0;
    }

    return MergeSort_Method(data);
  }

  int MergeSort_Method(const vector<int> & v) {
    int n = v.size();

    vector<int> a = v;
    vector<int> temp(n);

    int ans = 0;
    MergeSort(a, temp, ans, 0, n - 1);
    return ans;
  }

  void MergeSort(vector<int> & v, vector<int> & temp, int & ans, int l, int r) {
    if (l < r) {
      int mid = (l + r) / 2;
      MergeSort(v, temp, ans, l, mid);
      MergeSort(v, temp, ans, mid + 1, r);
      Merge(v, temp, ans, l, mid, r);
    }
  }

  void Merge(vector<int> &v, vector<int> & temp, int & ans, int l, int mid, int r) {
    int i = l, j = mid + 1, k = l;

    while (i <= mid && j <= r) {
      if (v[i] > v[j]) {
        temp[k++] = v[j++];
        ans = (1LL * ans + 1LL * (mid - i + 1)) % 1000000007;
      } else {
        temp[k++] = v[i++];
      }
    }
    
    while (i <= mid) temp[k++] = v[i++];
    while (j <= r) temp[k++] = v[j++];

    for (int i = l; i <= r; ++i) {
      v[i] = temp[i];
    }
  }

  int BIT_Method(const vector<int> & v) {
    int n = v.size();
    
    vector<int> disc = v;
    vector<int> a;

    sort(disc.begin(), disc.end());
    disc.erase(unique(disc.begin(), disc.end()), disc.end());
    for (int i = 0; i < n; ++i) {
      a.push_back(lower_bound(disc.begin(), disc.end(), v[i]) - disc.begin() + 1);
    }

    int ans = 0;
    c.assign(n + 1, 0);
    for (auto it = a.rbegin(); it != a.rend(); ++it) {
      int x = *it;
      ans = (1LL * ans + 1LL * qry(x - 1)) % 1000000007;
      add(x, n, 1);
    }
    return ans;
  }

  int qry(int x) {
    int sum = 0;
    while (x) {
      sum += 1LL * c[x];
      x -= x & (-x);
    }
    return sum;
  }

  void add(int x, int n, int k) {
    while (x <= n) {
      c[x] += k;
      x += x & (-x);
    }
  }
private:
  vector<int> c;
};


int main() {
  vector<int> a{7, 5, 2, 3};
  int t = Solution().MergeSort_Method(a);
  printf("%d\n ##", t);
}