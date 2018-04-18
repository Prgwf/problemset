class Solution {
public:
     int  NumberOf1(int n) {
       int y = n;
       int cnt = 0;
       while (n) {
         ++cnt;
         n = (n - 1) & n;
       }
       return max(cnt, __builtin_popcount(y));
     }
};
