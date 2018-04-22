class Solution {
 public:
  int minNumberInRotateArray(vector<int> rotateArray) {
    int n = rotateArray.size();

    if (n <= 0) {
      return 0;
    }

    int i = 0, j = n - 1;
    int mid = i;

    while (rotateArray[i] >= rotateArray[j]) {
      if (j - i == 1) {
        mid = j;
        break;
      }

      mid = (i + j) / 2;

      if (rotateArray[mid] == rotateArray[i] 
          && rotateArray[mid] == rotateArray[j]) {
        return *min_element(rotateArray.begin(), rotateArray.end());
      }

      if (rotateArray[mid] >= rotateArray[i]) {
        i = mid;
      } else if (rotateArray[mid] <= rotateArray[j]) {
        j = mid;
      }
    }

    return rotateArray[mid];
  }
};