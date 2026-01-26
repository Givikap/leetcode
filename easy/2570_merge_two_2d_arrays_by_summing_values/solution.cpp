using namespace std;

#include <vector>

class Solution {
public:
  vector<vector<int>> mergeArrays(vector<vector<int>> &nums1,
                                  vector<vector<int>> &nums2) {
    const int nums1Len = nums1.size();
    const int nums2Len = nums2.size();

    int i1 = 0, i2 = 0;

    vector<vector<int>> nums;
    nums.reserve(nums1Len + nums2Len);

    while (i1 < nums1Len && i2 < nums2Len) {
      if (nums1[i1][0] < nums2[i2][0])
        nums.push_back(nums1[i1++]);
      else if (nums1[i1][0] > nums2[i2][0])
        nums.push_back(nums2[i2++]);
      else
        nums.push_back(
            vector<int>{nums1[i1][0], nums1[i1++][1] + nums2[i2++][1]});
    }

    while (i1 < nums1Len)
      nums.push_back(nums1[i1++]);
    while (i2 < nums2Len)
      nums.push_back(nums2[i2++]);

    return nums;
  }
};
