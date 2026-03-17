#include <map>
#include <vector>

class Solution {
public:
  std::vector<int> relativeSortArray(std::vector<int> &arr1,
                                     std::vector<int> &arr2) {
    std::map<int, int> arr1Counter;
    for (const int &num : arr1)
      ++arr1Counter[num];

    std::vector<int> sortedArr;

    for (const int &num : arr2) {
      for (int _ = 0; _ < arr1Counter[num]; ++_)
        sortedArr.push_back(num);
      arr1Counter[num] = 0;
    }

    for (const auto &[num, count] : arr1Counter) {
      if (count != 0) {
        for (int _ = 0; _ < count; ++_)
          sortedArr.push_back(num);
      }
    }

    return sortedArr;
  }
};
