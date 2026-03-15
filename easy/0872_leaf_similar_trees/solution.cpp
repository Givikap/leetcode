#include "../../utils/cpp/nodes.hpp"
#include <vector>

class Solution {
public:
  bool leafSimilar(utils::TreeNode *root1, utils::TreeNode *root2) {
    std::vector<int> leafs1, leafs2;

    utils::TreeNode *node;

    for (auto &[root, leafs] :
         std::vector<std::pair<utils::TreeNode *, std::vector<int> *>>{
             {root1, &leafs1}, {root2, &leafs2}}) {
      std::vector<utils::TreeNode *> stack = {root};

      while (!stack.empty()) {
        node = stack.back();
        stack.pop_back();

        if (!node->left && !node->right) {
          leafs->push_back(node->val);
          continue;
        }

        if (node->left)
          stack.push_back(node->left);
        if (node->right)
          stack.push_back(node->right);
      }
    }

    return leafs1 == leafs2;
  }
};
