using namespace std;

#include <stack>
#include <unordered_map>
#include <vector>

class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    const int nums2Size = nums2.size();

    stack<int> stack;
    unordered_map<int, int> nextGreaterElementsMap;

    for (int i = nums2Size - 1; i >= 0; --i) {
      while (stack.size() > 0 && stack.top() <= nums2[i])
        stack.pop();

      if (!stack.empty())
        nextGreaterElementsMap[nums2[i]] = stack.top();
      else
        nextGreaterElementsMap[nums2[i]] = -1;

      stack.push(nums2[i]);
    }

    vector<int> nextGreaterElements;

    for (const int &num : nums1)
      nextGreaterElements.push_back(nextGreaterElementsMap[num]);

    return nextGreaterElements;
  }
};
