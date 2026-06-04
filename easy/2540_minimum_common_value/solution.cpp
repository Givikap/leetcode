#include <vector>

class Solution {
public:
  int getCommon(std::vector<int> &nums1, std::vector<int> &nums2) {
    const size_t n1 = nums1.size();
    const size_t n2 = nums2.size();

    size_t i1 = 0;
    size_t i2 = 0;

    while (i1 < n1 && i2 < n2) {
      if (nums1[i1] == nums2[i2])
        return nums1[i1];
      else if (nums1[i1] < nums2[i2])
        ++i1;
      else
        ++i2;
    }

    return -1;
  }
};
