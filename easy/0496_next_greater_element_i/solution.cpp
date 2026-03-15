#include <stack>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> nextGreaterElement(std::vector<int> &nums1,
                                      std::vector<int> &nums2) {
    const int nums2Size = nums2.size();

    std::stack<int> stack;
    std::unordered_map<int, int> nextGreaterElementsMap;

    for (int i = nums2Size - 1; i >= 0; --i) {
      while (stack.size() > 0 && stack.top() <= nums2[i])
        stack.pop();

      if (!stack.empty())
        nextGreaterElementsMap[nums2[i]] = stack.top();
      else
        nextGreaterElementsMap[nums2[i]] = -1;

      stack.push(nums2[i]);
    }

    std::vector<int> nextGreaterElements;

    for (const int &num : nums1)
      nextGreaterElements.push_back(nextGreaterElementsMap[num]);

    return nextGreaterElements;
  }
};
