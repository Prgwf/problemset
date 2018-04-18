struct Deque {
  int value, index;
  Deque() {}
  Deque(const int & v, const int & i)
    : value(v), index(i) {

    }
} ;

class Solution {
public:
  vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
    vector<Deque> Q(num.size() + 5);
    int head = 1, tail = 0;
    int k = size;
    for (int i = 0; i < k - 1; ++i) {
      while (head <= tail && Q[tail].value <= num[i]) {
        --tail;
      }
      ++tail;
      Q[tail].value = num[i];
      Q[tail].index = i;
    }
    vector<int> ans;
    for (int i = k - 1; i < num.size(); ++i) {
      while (head <= tail && Q[tail].value <= num[i]) {
        --tail;
      }
      ++tail;
      Q[tail].value = num[i];
      Q[tail].index = i;
      while (head <= tail && Q[head].index < i - k + 1) {
        ++head;
      }
      ans.push_back(Q[head].value);
    }
    return ans;
  }
} ;
