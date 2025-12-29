using namespace std;

#include <unordered_map>
#include <vector>

class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> nextGreaterElementsMap;

    const int nums1Size = nums1.size();
    const int nums2Size = nums2.size();

    for (int i = 0; i < nums2Size - 1; ++i) {
      for (int j = i + 1; j < nums2Size; ++j) {
        if (nums2[i] < nums2[j]) {
          nextGreaterElementsMap[nums2[i]] = nums2[j];
          break;
        }
      }
    }

    vector<int> nextGreaterElements;

    for (const int &num : nums1) {
      if (nextGreaterElementsMap.find(num) != nextGreaterElementsMap.end())
        nextGreaterElements.push_back(nextGreaterElementsMap[num]);
      else
        nextGreaterElements.push_back(-1);
    }

    return nextGreaterElements;
  }
};
