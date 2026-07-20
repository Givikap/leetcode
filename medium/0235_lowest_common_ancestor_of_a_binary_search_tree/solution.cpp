#include "../../utils/cpp/nodes.hpp"

class Solution {
public:
  utils::TreeNode *lowestCommonAncestor(utils::TreeNode *root,
                                        utils::TreeNode *p,
                                        utils::TreeNode *q) {
    utils::TreeNode *curr = root;

    while (true) {
      if (p->val < curr->val && q->val < curr->val)
        curr = curr->left;
      else if (p->val > curr->val && q->val > curr->val)
        curr = curr->right;
      else
        return curr;
    }

    return nullptr;
  }
};
