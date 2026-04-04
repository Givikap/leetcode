#include <vector>

class Solution {
public:
  bool validMountainArray(std::vector<int> &arr) {
    if (arr.size() < 3)
      return false;

    const size_t arrLen = arr.size();
    size_t i = 0;

    while (i < arrLen - 1 && arr[i] < arr[i + 1])
      ++i;

    if (i == 0 || i == arrLen - 1)
      return false;

    while (i < arrLen - 1 && arr[i] > arr[i + 1])
      ++i;

    return i == arrLen - 1;
  }
};
