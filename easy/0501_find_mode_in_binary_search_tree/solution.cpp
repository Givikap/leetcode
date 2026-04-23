#include "../../utils/cpp/nodes.hpp"
#include <stack>
#include <vector>

class Solution {
public:
  std::vector<int> findMode(utils::TreeNode *root) {
    std::vector<int> modes;
    int modeCount = 0;

    int currVal = -100001;
    int currCount = 0;

    utils::TreeNode *curr = root;
    std::stack<utils::TreeNode *> s;

    while (curr || !s.empty()) {
      while (curr) {
        s.push(curr);
        curr = curr->left;
      }

      utils::TreeNode *node = s.top();
      s.pop();

      if (currVal != node->val) {
        currVal = node->val;
        currCount = 1;
      } else
        ++currCount;

      if (currCount >= modeCount) {
        if (currCount > modeCount) {
          modes.clear();
          modeCount = currCount;
        }
        modes.push_back(node->val);
      }

      curr = node->right;
    }

    return modes;
  }
};
