#include <vector>

class Solution {
public:
  double findMedianSortedArrays(std::vector<int> &nums1,
                                std::vector<int> &nums2) {
    std::vector<int>::iterator it1 = nums1.begin();
    std::vector<int>::iterator it2 = nums2.begin();

    std::vector<int>::iterator prev, curr;

    for (size_t _ = 0; _ < (nums1.size() + nums2.size()) / 2 + 1; ++_) {
      prev = curr;

      if (it2 == nums2.end() || (it1 != nums1.end() && *it1 < *it2))
        curr = it1++;
      else
        curr = it2++;
    }

    if ((nums1.size() + nums2.size()) % 2 == 0)
      return (float)(*prev + *curr) / 2;
    else
      return *curr;
  }
};
