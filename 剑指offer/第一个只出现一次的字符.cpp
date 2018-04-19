class Solution {
 public:
  int FirstNotRepeatingChar(string str) {
    int n = str.size();
    if (n <=0) {
      return -1;
    }

    unsigned int cnt[256];
    memset(cnt, 0, sizeof(cnt));

    for (const char & ch : str) {
      cnt[ch]++;
    }
    
    for (int i = 0; i < n; ++i) {
      if (cnt[str[i]] == 1) {
        return i;
      }
    }
    return -1;
  }
};