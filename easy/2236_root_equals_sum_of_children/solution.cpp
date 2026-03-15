#include "../../utils/cpp/nodes.hpp"

class Solution {
public:
  bool checkTree(utils::TreeNode *root) {
    return root->val == root->left->val + root->right->val;
  }
};
