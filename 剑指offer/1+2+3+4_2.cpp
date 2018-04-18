class A {
public:
  virtual unsigned int Sum(unsigned int n) {
    return 0;
  }
};
A * Array[2];

class B: public A {
public:
  virtual unsigned int Sum(unsigned int n) {
    return Array[!!n]->Sum(n - 1) + n;
  }
} ;
class Solution {
public:
    unsigned int Sum_Solution(int n) {
      A a;
      B b;
      Array[0] = &a;
      Array[1] = &b;

      int value = Array[1]->Sum(n);
      return value;
    }
};
