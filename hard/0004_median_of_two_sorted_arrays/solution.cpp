using namespace std;

#include <vector>

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    vector<int> nums;

    vector<int>::iterator i1 = nums1.begin();
    vector<int>::iterator i2 = nums2.begin();

    int medianIndex = (nums1.size() + nums2.size()) / 2;

    while (true) {
      if (nums.size() > medianIndex)
        break;

      if (i1 != nums1.end() && i2 != nums2.end()) {
        if (*i1 < *i2)
          nums.push_back(*i1++);
        else
          nums.push_back(*i2++);
      } else {
        if (i1 != nums1.end())
          nums.push_back(*i1++);
        if (i2 != nums2.end())
          nums.push_back(*i2++);
      }
    }

    if ((nums1.size() + nums2.size()) & 1)
      return *(nums.end() - 1);
    else
      return double(*(nums.end() - 1) + *(nums.end() - 2)) / 2;
  }
};
