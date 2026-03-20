#include "../../utils/cpp/nodes.hpp"
#include <stack>
#include <vector>

class Solution {
public:
  int kthSmallest(utils::TreeNode *root, int k) {
    utils::TreeNode *curr = root;
    std::stack<utils::TreeNode *> s;

    std::vector<int> values;

    while (curr || !s.empty()) {
      while (curr) {
        s.push(curr);
        curr = curr->left;
      }

      utils::TreeNode *node = s.top();
      s.pop();

      values.push_back(node->val);
      curr = node->right;
    }

    return values[k - 1];
  }
};
