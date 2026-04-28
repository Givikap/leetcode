#include "../../utils/cpp/nodes.hpp"

class Solution {
public:
  utils::TreeNode *searchBST(utils::TreeNode *root, int val) {
    while (root) {
      if (root->val == val)
        return root;
      else if (root->val < val)
        root = root->right;
      else
        root = root->left;
    }

    return nullptr;
  }
};
