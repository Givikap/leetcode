using namespace std;

#include <vector>

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    vector<int>::iterator it1 = nums1.begin();
    vector<int>::iterator it2 = nums2.begin();

    vector<int>::iterator prev, curr;

    for (int i = 0; i < (nums1.size() + nums2.size()) / 2 + 1; ++i) {
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
