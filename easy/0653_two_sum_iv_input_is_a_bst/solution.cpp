#include "../../utils/cpp/nodes.hpp"
#include <stack>
#include <vector>

class Solution {
public:
  bool findTarget(utils::TreeNode *root, int k) {
    utils::TreeNode *curr = root;

    std::stack<utils::TreeNode *> s;
    std::vector<int> sortedVals;

    while (curr || !s.empty()) {
      while (curr) {
        s.push(curr);
        curr = curr->left;
      }

      sortedVals.push_back(s.top()->val);
      curr = s.top()->right;

      s.pop();
    }

    size_t left = 0;
    size_t right = sortedVals.size() - 1;

    while (left < right) {
      int currSum = sortedVals[left] + sortedVals[right];

      if (currSum == k)
        return true;
      else if (currSum < k)
        ++left;
      else
        --right;
    }

    return false;
  }
};
