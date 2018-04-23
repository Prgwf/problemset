class Solution {
 public:
  void push(int node) {
    stack1.push(node);
  }

  int pop() {
    if (stack2.empty()) {
      while (stack1.size()) {
        int value = stack1.top();
        stack1.pop();
        stack2.push(value);
      }
    }

    if (stack2.empty()) {
      return 0;
    }

    int u = stack2.top();
    stack2.pop();
    return u;
  }

 private:
  stack<int> stack1;
  stack<int> stack2;
};